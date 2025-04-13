let TanksNumber;
let gaugePressureFV = [];  // Initialize as empty array
let lastPressureValues = [];  // Store last received pressure values

// Variables for WebSockets
var gateway = `ws://${window.location.hostname}/ws`;
var websocket = new WebSocket(gateway);

// Get current sensor readings when the page loads  
//window.addEventListener('load', getReadings);
window.addEventListener('load', onLoad);

function onLoad(event) {
  initWebSocket();
}
// WebSocket handling

function initWebSocket() {
  console.log('Trying to open a WebSocket connection...');
  websocket.onopen = onOpen;
  websocket.onclose = onClose;
  websocket.onmessage = function (e) {
    processCommand(e);
  };
}

function onOpen(event) {
  console.log('Connection opened');
}

function onClose(event) {
  console.log('Connection closed');
}

function processCommand(e) {
  console.log("ws new readings", e.data);
  const myObj = JSON.parse(e.data);
  console.log(myObj);

  // Store pressure values
  lastPressureValues = myObj.pressure;

  // Get number of tanks from Configuration object
  const newTanksNumber = myObj.Configuration.tanksNumber;
  
  // Update title and initialize gauges if number of tanks changed
  if (TanksNumber !== newTanksNumber) {
    TanksNumber = newTanksNumber;
    document.getElementById('controllerTitle').textContent = 
        `${TanksNumber} Channel Pressure Controller`;
    createTankCards();  // Create cards first
    setTimeout(() => {
        createGauges();
        // Update gauges with last known values immediately
        updateGauges(lastPressureValues);
    }, 100);
  } else {
    // Regular update
    updateGauges(lastPressureValues);
  }
}

// Separate function for updating gauge values
function updateGauges(pressureValues) {
  if (gaugePressureFV.length > 0) {
    for (let i = 0; i < TanksNumber; i++) {
      if (gaugePressureFV[i] && pressureValues[i] !== undefined) {
        gaugePressureFV[i].value = pressureValues[i];
      }
    }
  }
}

function createGauges() {
  gaugePressureFV = [];  // Clear existing gauges
  for (let i = 0; i < TanksNumber; i++) {
    const canvasId = `fv${i + 1}-gauge-pressure`;
    const canvas = document.getElementById(canvasId);
    
    if (canvas) {  // Only create gauge if canvas exists
      gaugePressureFV[i] = new RadialGauge({
        renderTo: canvas,  // Specify the canvas element
        width: 250,
        height: 250,
        units: "Pressure (bar)",
        minValue: 0,
        maxValue: 2.5,
        colorValueBoxRect: "#049faa",
        colorValueBoxRectEnd: "#049faa",
        colorValueBoxBackground: "#f1fbfc",
        valueInt: 1,
        valueDec: 3,
        majorTicks: [
          "0",
          "0.5",
          "1",
          "1.5",
          "2",
          "2.5"
        ],
        minorTicks: 5,
        strokeTicks: true,
        highlights: [
          {
            "from": 0.6,
            "to": 0.85,
            "color": "#03C0C1",
          },
          {
            "from": 2,
            "to": 2.5,
            "color": "rgba(255, 35, 119, 0.7)"
          }
        ],
        colorPlate: "#fff",
        borderShadowWidth: 0,
        borders: false,
        needleType: "line",
        colorNeedle: "#007F80",
        colorNeedleEnd: "#007F80",
        needleWidth: 2,
        needleCircleSize: 3,
        colorNeedleCircleOuter: "#007F80",
        needleCircleOuter: true,
        needleCircleInner: false,
        animationDuration: 1500,
        animationRule: "linear"
      }).draw();
    }
  }
}

function createTankCards() {
  const cardGrid = document.querySelector('.card-grid');
  cardGrid.innerHTML = '';  // Clear existing cards
  
  for (let i = 0; i < TanksNumber; i++) {
    const tankNum = i + 1;
    const card = document.createElement('div');
    card.className = 'card';
    card.innerHTML = `
      <p class="card-title">FV${tankNum}</p>
      <canvas id="fv${tankNum}-gauge-pressure"></canvas>
      <a href="/fv${tankNum}settings.html">
        <button class="button">FV${tankNum} Settings</button>
      </a>
    `;
    cardGrid.appendChild(card);
  }
}

// Menu handling
function toggleMenu() {
  const dropdown = document.getElementById("myDropdown");
  dropdown.classList.toggle("show");
  
  // Stop event propagation to prevent immediate closing
  event.stopPropagation();
}

// Close the dropdown if clicked outside
window.addEventListener('click', function(event) {
  if (!event.target.matches('.hamburger-menu')) {
    const dropdowns = document.getElementsByClassName("dropdown");
    Array.from(dropdowns).forEach(dropdown => {
      if (dropdown.classList.contains('show')) {
        dropdown.classList.remove('show');
      }
    });
  }
});