document.addEventListener('DOMContentLoaded', function() {
  var updateForm = document.querySelector('.updateForm');
  var progressWrapper = document.querySelector('.progressWrapper');
  var progressBar = document.querySelector('.progressBar');
  var progressText = document.querySelector('.progressText');
  var restartMessage = document.querySelector('.restartMessage');
  var countdownDiv = document.getElementById('countdown');
  var countdownValue = document.getElementById('countdownValue');
  var homeButton = document.getElementById('homeButton');
  var submitButton = updateForm.querySelector('input[type="submit"]');
  var fileInput = document.getElementById('update');
  var firmwareVersionSpan = document.getElementById('firmwareVersion');

  // Fetch the current firmware version from the ESP32
  fetch('/firmware_version')
    .then(response => response.text())
    .then(currentVersion => {
      firmwareVersionSpan.innerText = currentVersion;
    })
    .catch(error => {
      console.error('Error fetching firmware version:', error);
      firmwareVersionSpan.innerText = 'Error';
    });

  // Hide the submit button initially
  submitButton.style.display = 'none';

  // Add event listener to the file input to detect file selection
  fileInput.addEventListener('change', function() {
    if (fileInput.files.length > 0) {
      // Extract the firmware version from the filename (e.g., firmware_v1.4.0.bin)
      var fileName = fileInput.files[0].name;
      var match = fileName.match(/_v([0-9]+\.[0-9]+\.[0-9]+)\.bin$/);
      if (match) {
        var newVersion = match[1];
        var currentVersion = firmwareVersionSpan.innerText;

        // Compare versions
        if (newVersion > currentVersion) {
          // Enable the submit button if the new version is greater
          submitButton.style.display = 'inline-block';
        } else {
          // Alert the user but still allow them to proceed
          var userConfirm = confirm('The selected firmware version is not newer than the current version. Do you want to proceed anyway?');
          if (userConfirm) {
            submitButton.style.display = 'inline-block';
          } else {
            fileInput.value = '';
            submitButton.style.display = 'none';
          }
        }
      } else {
        alert('Invalid firmware file. Please select a valid .bin file with versioning.');
        fileInput.value = '';
        submitButton.style.display = 'none';
      }
    } else {
      // No file selected, hide the submit button
      submitButton.style.display = 'none';
    }
  });

  updateForm.onsubmit = function(event) {
    event.preventDefault(); // Prevent the form from submitting normally
    var formData = new FormData(updateForm);
    var xhr = new XMLHttpRequest();

    // Show the progress bar when upload starts
    progressWrapper.style.display = 'block';

    // Disable the submit button
    submitButton.disabled = true;

    // Hide the restart message (if previously shown)
    restartMessage.style.display = 'none';

    // Hide the countdown (if previously shown)
    countdownDiv.style.display = 'none';

    xhr.upload.addEventListener('progress', function(event) {
      if (event.lengthComputable) {
        var percentComplete = (event.loaded / event.total) * 100;
        progressBar.style.width = percentComplete + '%';
        progressText.innerHTML = Math.round(percentComplete) + '%';
      } else {
        console.log('Unable to compute progress information.');
      }
    });

    xhr.addEventListener('load', function(event) {
      if (xhr.status == 200) {
        console.log('Upload complete.');
        restartMessage.style.display = 'block';
        restartMessage.innerHTML = '<p>' + xhr.responseText + '</p>';
        
        // Start the countdown
        var countdown = 10;
        countdownDiv.style.display = 'block';
        countdownValue.innerText = countdown;
        
        var countdownInterval = setInterval(function() {
          countdown--;
          countdownValue.innerText = countdown;
          if (countdown <= 0) {
            clearInterval(countdownInterval);
            
            // Hide elements and show the Home button
            progressWrapper.style.display = 'none';
            submitButton.style.display = 'none';
            restartMessage.style.display = 'none';
            countdownDiv.style.display = 'none';
            homeButton.style.display = 'inline-block';
          }
        }, 1000);
      } else {
        alert('Upload failed');
      }
    });

    xhr.addEventListener('error', function(event) {
      alert('An error occurred while transferring the file.');
      // Re-enable the submit button
      submitButton.disabled = false;
    });

    xhr.addEventListener('abort', function(event) {
      alert('The upload has been canceled by the user or the browser dropped the connection.');
      // Re-enable the submit button
      submitButton.disabled = false;
    });

    xhr.open('POST', '/update');
    xhr.send(formData);
  };

  // Add event listener to the Home button
  homeButton.addEventListener('click', function() {
    window.location.href = 'index.html';
  });
});
