// Variables for WebSocket
var gateway = `ws://${window.location.hostname}/ws`;
var websocket = new WebSocket(gateway);

// Get current sensor readings when the page loads  
window.addEventListener('load', function() {
    // Disable fields by default
    disableFields();
    initWebSocket();
});

function onLoad(event) {
    initWebSocket();
}

function initWebSocket() {
    console.log('Trying to open a WebSocket connection...');
    websocket.onopen = onOpen;
    websocket.onclose = onClose;
    websocket.onmessage = onMessage;
}

function onOpen(event) {
    console.log('Connection opened');
}

function onClose(event) {
    console.log('Connection closed');
    setTimeout(initWebSocket, 2000);
}

function onMessage(event) {
    const myObj = JSON.parse(event.data);
    console.log(myObj);
    
    // Handle configuration success/failure response
    if (myObj.success !== undefined) {
        const statusDiv = document.getElementById('statusMessage');
        // Reset display style first
        statusDiv.style.display = 'block';
        
        if (myObj.success) {
            statusDiv.textContent = 'Configuration saved successfully';
            statusDiv.className = 'status-message success';
        } else {
            statusDiv.textContent = 'Failed to save configuration';
            statusDiv.className = 'status-message error';
        }
        // Hide message after 3 seconds
        setTimeout(() => {
            statusDiv.style.display = 'none';
        }, 3000);
        return;
    }
    
    // Handle regular configuration updates
    if (myObj.Configuration) {
        document.getElementById('tempConfig').value = myObj.Configuration.tempConfig;
        document.getElementById('pressureConfig').value = myObj.Configuration.pressureConfig;
    }
}

// Save configuration
function saveConfig(event) {
    event.preventDefault();
    
    const config = {
        command: "saveconfig",
        tempConfig: parseInt(document.getElementById('tempConfig').value),
        pressureConfig: parseInt(document.getElementById('pressureConfig').value)
    };
    console.log(config);
    websocket.send(JSON.stringify(config));
}

function disableFields() {
    document.getElementById('tempConfig').disabled = true;
    document.getElementById('pressureConfig').disabled = true;
}

function enableFields() {
    document.getElementById('tempConfig').disabled = false;
    document.getElementById('pressureConfig').disabled = false;
}

function unlockSetup() {
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
    pinModalContent.style.position = 'relative';  // Added for close button positioning

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
    submitButton.className = 'button';
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
        enableFields();
        document.getElementById('pinModal').remove();
    } else {
        alert("Incorrect PIN. Access denied.");
        document.getElementById('lock').checked = false;
        disableFields();
        document.getElementById('pinModal').remove();
    }
}

// Add event listener for checkbox
document.getElementById('lock').addEventListener('click', unlockSetup);