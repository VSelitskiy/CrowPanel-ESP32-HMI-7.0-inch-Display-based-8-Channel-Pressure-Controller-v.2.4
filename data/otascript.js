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
  var fileTypeSelect = document.getElementById('fileType');
  var fileInput = document.getElementById('update');
  var firmwareVersionSpan = document.getElementById('firmwareVersion');

  // Set the initial file input accept attribute based on the selected file type .bin
  fileTypeSelect.addEventListener('change', function() {
    if (fileTypeSelect.value === 'firmware') {
      fileInput.setAttribute('accept', '.bin');
    } else if (fileTypeSelect.value === 'filesystem') {
      fileInput.setAttribute('accept', '.bin');
      // Could be generalized if you want different extensions
    }
  });

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
        alert('Upload failed: ' + (xhr.responseText || ('HTTP ' + xhr.status)));
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

let modalIsActive = false;

function disableUpdate() {
  console.log('disableUpdate: disabling update controls');
  const submitButton = document.getElementById('submitButton');
  if (submitButton) {
    submitButton.disabled = true;
    submitButton.style.display = 'none'; // Скрываем кнопку при деактивации
  }
  const fileInput = document.getElementById('update');
  if (fileInput) fileInput.disabled = true;
}

function unlockSetup() {
  const lockCheckbox = document.getElementById('lock');
  console.log(`unlockSetup: lock.checked = ${lockCheckbox.checked}`);
  if (lockCheckbox.checked) {
    modalIsActive = false; // сброс для гарантии повторного открытия модала
    disableUpdate(); // блокируем пока не прошли PIN
    showPinModal();
  } else {
    disableUpdate();
    // Дополнительно: убедимся, что кнопка Update скрыта при снятом чекбоксе
    // disableUpdate() уже скрывает кнопку, так что этого достаточно
  }
}


function enableUpdate() {
  console.log('enableUpdate: enabling update controls');
  const submitButton = document.getElementById('submitButton');
  if (submitButton) {
    submitButton.disabled = false;
    submitButton.style.display = 'inline-block';
  }
  const fileInput = document.getElementById('update');
  if (fileInput) fileInput.disabled = false;
}

function createPinModal() {
  if (modalIsActive || document.getElementById('pinModal')) {
    console.log('createPinModal: modal already active or exists, exiting');
    return;
  }
  modalIsActive = true;
  console.log('createPinModal: creating modal window');

  const pinModal = document.createElement('div');
  pinModal.id = 'pinModal';
  pinModal.style.display = 'block';
  pinModal.style.position = 'fixed';
  pinModal.style.zIndex = '1000'; // чтобы быть поверх
  pinModal.style.left = '0';
  pinModal.style.top = '0';
  pinModal.style.width = '100%';
  pinModal.style.height = '100%';
  pinModal.style.overflow = 'auto';
  pinModal.style.backgroundColor = 'rgba(0,0,0,0.4)';

  const pinModalContent = document.createElement('div');
  pinModalContent.style.backgroundColor = '#fefefe';
  pinModalContent.style.margin = '15% auto';
  pinModalContent.style.padding = '20px';
  pinModalContent.style.border = '1px solid #888';
  pinModalContent.style.width = '80%';
  pinModalContent.style.maxWidth = '300px';
  pinModalContent.style.position = 'relative';

  const closeButton = document.createElement('span');
  closeButton.innerHTML = '&times;';
  closeButton.style.position = 'absolute';
  closeButton.style.right = '10px';
  closeButton.style.top = '5px';
  closeButton.style.fontSize = '20px';
  closeButton.style.fontWeight = 'bold';
  closeButton.style.cursor = 'pointer';

  closeButton.onclick = function() {
    console.log('closeButton.onclick: user closed the modal');
    const lockCheckbox = document.getElementById('lock');

    modalIsActive = false;
    lockCheckbox.removeEventListener('click', unlockSetup);
    lockCheckbox.checked = false;
    console.log('closeButton.onclick: set lock.checked = false');

    setTimeout(() => {
      lockCheckbox.addEventListener('click', unlockSetup);
      disableUpdate();
      console.log('closeButton.onclick: unlockSetup handler added, update disabled');
    }, 10);

    pinModal.remove();
    console.log('closeButton.onclick: modal removed from DOM');
  };
  pinModalContent.appendChild(closeButton);

  const pinLabel = document.createElement('p');
  pinLabel.textContent = 'Please enter the 4-digit PIN code:';
  pinModalContent.appendChild(pinLabel);

  const pinInput = document.createElement('input');
  pinInput.type = 'password';
  pinInput.id = 'pinInput';
  pinInput.maxLength = 4;
  pinInput.style.padding = '10px';
  pinInput.style.width = '100%';
  pinInput.style.boxSizing = 'border-box';
  pinInput.style.marginBottom = '10px';
  pinModalContent.appendChild(pinInput);

  const submitButton = document.createElement('button');
  submitButton.textContent = 'Submit';
  submitButton.className = 'button';
  submitButton.onclick = function(e) {
    e.preventDefault();
    console.log('submitButton.onclick: user clicked Submit');
    submitPin();
  };
  pinModalContent.appendChild(submitButton);

  pinModal.appendChild(pinModalContent);
  document.body.appendChild(pinModal);
  console.log('createPinModal: modal added to DOM');

  pinInput.focus();
  console.log('createPinModal: input focused');

  pinInput.addEventListener('keyup', function(e) {
    if (e.key === 'Enter') {
      console.log('pinInput: Enter pressed, submitting PIN');
      submitPin();
    }
  });
}

function showPinModal() {
  console.log('showPinModal: showing modal window');
  createPinModal();
}

function hidePinModal() {
  const pinModal = document.getElementById('pinModal');
  if (pinModal) {
    pinModal.remove();
    console.log('hidePinModal: modal removed');
  } else {
    console.log('hidePinModal: no modal found');
  }
}

function submitPin() {
  const enteredPinElem = document.getElementById('pinInput');
  if (!enteredPinElem) {
    console.log('submitPin: PIN input not found, exiting');
    return;
  }
  const enteredPin = enteredPinElem.value.trim();
  console.log(`submitPin: entered PIN = "${enteredPin}"`);
  const correctPin = "0808";
  const lockCheckbox = document.getElementById('lock');

  if (enteredPin === correctPin) {
    console.log('submitPin: PIN correct, enabling update');
    enableUpdate();

    lockCheckbox.removeEventListener('click', unlockSetup);
    lockCheckbox.checked = true;
    lockCheckbox.addEventListener('click', unlockSetup);
    console.log('submitPin: set lock.checked = true, handler reattached');

    hidePinModal();
    modalIsActive = false; // сброс флага
  } else {
    console.log('submitPin: incorrect PIN, showing alert');
    alert("Incorrect PIN. Access denied.");

    lockCheckbox.removeEventListener('click', unlockSetup);
    lockCheckbox.checked = false;
    lockCheckbox.addEventListener('click', unlockSetup);
    console.log('submitPin: set lock.checked = false, handler reattached');

    disableUpdate();

    setTimeout(() => {
      hidePinModal();
      modalIsActive = false; // сброс
      console.log('submitPin: modal hidden, modalIsActive reset to false after incorrect PIN');
    }, 0);
  }
}

// Внутри DOMContentLoaded после остального init
document.addEventListener('DOMContentLoaded', function() {
  disableUpdate(); // изначально input и submit заблокированы

  const lockCheckbox = document.getElementById('lock');
  lockCheckbox.addEventListener('click', unlockSetup);
  console.log('unlockSetup handler attached to lock checkbox');
});
