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
var _Number = tankNumber.trim().slice(2);  // trim added to be safe

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

document.getElementById('settingsForm').addEventListener('submit', function(event) {
  event.preventDefault();
  saveSettings();
});

document.getElementById('calibrationForm').addEventListener('submit', function(event) {
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
    // Only blank values are invalid (allow zero)
    if (collection1[i].value.trim() === "") {
      alert("Fill in all values!");
      requestSettings();
      return;
    }
  }

  const collection = document.getElementsByClassName("fv-mode");
  for (let i = 0; i < collection.length; i++) {
    if (collection[i].value.trim() === "") {
      alert("Select Mode!");
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

  var msg = {
    "tankNumber": _Number,
    "setPressure": setPressure,
    "pressureDifferential": pressureDifferential,
    "pressureMode": pressureMode,
    "volts_4": volts_4,
    "volts_20": volts_20,
    "sensorRange": sensorRange,
    "request": 1
  };
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
    document.getElementById('pressureDifferential').value = pressureDifferential;

    volts_4 = Number(myObj.volts_4).toFixed(3);
    document.getElementById('volts_4').value = volts_4;

    volts_20 = Number(myObj.volts_20).toFixed(3);
    document.getElementById('volts_20').value = volts_20;

    sensorRange = Number(myObj.sensorRange).toFixed(1);
    document.getElementById('sensorRange').value = sensorRange;
  }
};

let modalIsActive = false;

function disableFields() {
  console.log('disableFields: disabling fields');
  ['volts_4', 'volts_20', 'sensorRange'].forEach(id => {
    const el = document.getElementById(id);
    if (el) el.disabled = true;
  });
}

function enableFields() {
  console.log('enableFields: enabling fields');
  ['volts_4', 'volts_20', 'sensorRange'].forEach(id => {
    const el = document.getElementById(id);
    if (el) el.disabled = false;
  });
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
      disableFields();
      console.log('closeButton.onclick: unlockSetup handler added, fields disabled');
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

function unlockSetup() {
  const lockCheckbox = document.getElementById('lock');
  console.log(`unlockSetup: lock.checked = ${lockCheckbox.checked}`);

  if (lockCheckbox.checked) {
    // Сбрасываем модальный флаг, чтобы разрешить создание модального окна заново
    modalIsActive = false;

    // Показать PIN-модал
    showPinModal();

    // При этом поля пока остаются заблокированными, пока не подтвердится PIN
    disableFields();

  } else {
    disableFields();
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
    console.log('submitPin: PIN correct, enabling fields');
    enableFields();

    lockCheckbox.removeEventListener('click', unlockSetup);
    lockCheckbox.checked = true;
    lockCheckbox.addEventListener('click', unlockSetup);
    console.log('submitPin: set lock.checked = true, handler reattached');

    hidePinModal();
  } else {
    console.log('submitPin: incorrect PIN, showing alert');
  alert("Incorrect PIN. Access denied.");

  lockCheckbox.removeEventListener('click', unlockSetup);
  lockCheckbox.checked = false;
  lockCheckbox.addEventListener('click', unlockSetup);
  console.log('submitPin: set lock.checked = false, handler reattached');

  disableFields();

  setTimeout(() => {
    hidePinModal();
    modalIsActive = false;  // <--- Добавьте здесь сброс флага!
    console.log('submitPin: modal hidden, modalIsActive reset to false after incorrect PIN');
  }, 0);
  }
}

window.addEventListener('load', () => {
  console.log('window.load: page loaded, initializing');
  disableFields();

  const lockCheckbox = document.getElementById('lock');
  lockCheckbox.addEventListener('click', unlockSetup);
  console.log('window.load: unlockSetup handler attached to lock checkbox');
});
