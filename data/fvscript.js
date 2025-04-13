var pressureMode;
var setPressure;
var pressureDifferential;
var volts_4;
var volts_20;
var sensorRange;

// Variables for websocket1s
var gateway = `ws://${window.location.hostname}/ws1`;
var websocket1 = new WebSocket(gateway);

window.addEventListener('load', onLoad);
// window.addEventListener('pageswap', unLoad);

var tankNumber = document.getElementById('tankNumber').innerHTML;
var _Number = tankNumber.slice(2);

// function unLoad(event) {
//   websocket1.close();
// }

function onLoad(event) {
  initwebsocket1();
  requestSettings();

}
// websocket1 handling

function initwebsocket1() {
  console.log('Trying to open a websocket1 connection...');
  websocket1.onopen = onOpen;
  websocket1.onclose = onClose;
  websocket1.onmessage = function (e) {
    processCommand(e);
  };
}

document.getElementById('compression').addEventListener('click', mode_changed);
document.getElementById('release').addEventListener('click', mode_changed);
document.getElementById('lock').addEventListener('click', unlockSetup);

document.querySelector('.card-grid-2 form:first-of-type').addEventListener('submit', function(event) {
    event.preventDefault();
    saveSettings();
});

document.querySelector('.card-grid-2 form:last-of-type').addEventListener('submit', function(event) {
    event.preventDefault();
    saveSettings();
});

function onOpen(event) {
  console.log('Connection opened');
  setTimeout(requestSettings, 50);
  //requestSettings();
}

function onClose(event) {
  console.log('Connection closed');
  // setTimeout(initwebsocket1, 2000);
}

function requestSettings() {
  var msg = { "tankNumber": _Number, "request": 0 };
  console.log(JSON.stringify(msg));
  websocket1.send(JSON.stringify(msg));
}

function saveSettings() {

  const collection1 = document.getElementsByClassName("fv-settings");
  for (let i = 0; i < collection1.length; i++) {
    console.log(collection1.length);
    if (collection1[i].value == "" || collection1[i].value == 0) {
      alert("Fill in all values!")
      requestSettings();
      return;
    }
  }

  const collection = document.getElementsByClassName("fv-mode");
  for (let i = 0; i < collection.length; i++) {
    console.log(collection.length);
    if (collection[i].value == "") {
      alert("Select Mode!")
      requestSettings();
      return;
    }
  }

  if (document.getElementById('release').checked == true) {
    pressureMode = 1;
  } else {
    pressureMode = 0;
  }
  setPressure = document.getElementById('setPressure').value;
  pressureDifferential = document.getElementById('pressureDifferential').value;
  volts_4 = document.getElementById('volts_4').value;
  volts_20 = document.getElementById('volts_20').value;
  sensorRange = document.getElementById('sensorRange').value;
  var msg = { "tankNumber": _Number, "setPressure": setPressure, "pressureDifferential": pressureDifferential, "pressureMode": pressureMode, "volts_4": volts_4, "volts_20": volts_20, "sensorRange": sensorRange, "request": 1 };
  console.log(JSON.stringify(msg));
  websocket1.send(JSON.stringify(msg));
}

function mode_changed() {

  if (document.getElementById('release').checked == true) {
    pressureMode = 1;
  } else {
    pressureMode = 0;
  }
  console.log(pressureMode);
}

function unlockSetup() {
  const correctPin = "0808"; // Define your 4-digit PIN code here
  const lockCheckbox = document.getElementById('lock');
  if (lockCheckbox.checked) {
    createPinModal();
  } else {
    disableFields();
  }
}

function createPinModal() {
  const pinModal = document.createElement('div');
  pinModal.id = 'pinModal';
  pinModal.style.display = 'block';
  pinModal.style.position = 'fixed';
  pinModal.style.zIndex = '1';
  pinModal.style.left = '0';
  pinModal.style.top = '0';
  pinModal.style.width = '100%';
  pinModal.style.height = '100%';
  pinModal.style.overflow = 'auto';
  pinModal.style.backgroundColor = 'rgba(0,0,0,0.4)';

  const pinModalContent = document.createElement('div');
  pinModalContent.id = 'pinModalContent';
  pinModalContent.style.backgroundColor = '#fefefe';
  pinModalContent.style.margin = '15% auto';
  pinModalContent.style.padding = '20px';
  pinModalContent.style.border = '1px solid #888';
  pinModalContent.style.width = '80%';
  pinModalContent.style.maxWidth = '300px';
  pinModalContent.style.position = 'relative';  // Added for close button

  // Add close button
  const closeButton = document.createElement('span');
  closeButton.innerHTML = '&times;';
  closeButton.style.position = 'absolute';
  closeButton.style.right = '10px';
  closeButton.style.top = '5px';
  closeButton.style.fontSize = '20px';
  closeButton.style.fontWeight = 'bold';
  closeButton.style.cursor = 'pointer';
  closeButton.onclick = function() {
      document.getElementById('lock').checked = false;
      disableFields();
      document.getElementById('pinModal').remove();
  };

  pinModalContent.appendChild(closeButton);

  const pinLabel = document.createElement('p');
  pinLabel.textContent = 'Please enter the 4-digit PIN code:';

  const pinInput = document.createElement('input');
  pinInput.type = 'password';
  pinInput.id = 'pinInput';
  pinInput.style.padding = '10px';
  pinInput.style.width = '100%';
  pinInput.style.boxSizing = 'border-box';
  pinInput.style.marginBottom = '10px';

  const submitButton = document.createElement('button');
  submitButton.textContent = 'Submit';
  submitButton.className = 'button'; // Add the button class
  submitButton.onclick = submitPin;

  pinModalContent.appendChild(pinLabel);
  pinModalContent.appendChild(pinInput);
  pinModalContent.appendChild(submitButton);

  pinModal.appendChild(pinModalContent);
  document.body.appendChild(pinModal);
  
  // Set focus to PIN input
  pinInput.focus();
}

function submitPin() {
  const enteredPin = document.getElementById('pinInput').value;
  const correctPin = "0808";
  if (enteredPin === correctPin) {
    document.getElementById('volts_4').removeAttribute('disabled');
    document.getElementById('volts_20').removeAttribute('disabled');
    document.getElementById('sensorRange').removeAttribute('disabled');
    document.getElementById('pinModal').remove();
  } else {
    alert("Incorrect PIN. Access denied.");
    document.getElementById('lock').checked = false;
    disableFields();
    document.getElementById('pinModal').remove();
  }
}

function disableFields() {
  document.getElementById('volts_4').setAttribute('disabled', '');
  document.getElementById('volts_20').setAttribute('disabled', '');
  document.getElementById('sensorRange').setAttribute('disabled', '');
}

document.getElementById('lock').addEventListener('click', unlockSetup);

function processCommand(e) {

  console.log("ws new settings", e.data);
  var myObj = JSON.parse(e.data);
  console.log(myObj);
  var rx_number = myObj.tankNumber;
  if (_Number == rx_number) {
    pressureMode = myObj.pressureMode;
    if (pressureMode == 1) {
      document.getElementById('release').checked = true;
    } else {
      document.getElementById('compression').checked = true;
    }
    setPressure = Number(myObj.setPressure).toFixed(3);
    document.getElementById('setPressure').value = setPressure;
    pressureDifferential = Number(myObj.pressureDifferential).toFixed(3);
    document.getElementById('pressureDifferential').setAttribute('value', pressureDifferential);
    volts_4 = Number(myObj.volts_4).toFixed(3);
    document.getElementById('volts_4').setAttribute('value', volts_4);
    volts_20 = Number(myObj.volts_20).toFixed(3);
    document.getElementById('volts_20').setAttribute('value', volts_20);
    sensorRange = Number(myObj.sensorRange).toFixed(3);
    document.getElementById('sensorRange').setAttribute('value', sensorRange);
  }
};