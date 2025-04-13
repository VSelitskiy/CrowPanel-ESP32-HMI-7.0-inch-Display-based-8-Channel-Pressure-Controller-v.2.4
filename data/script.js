let TanksNumber;
let gaugePressureFV = [];  // Initialize as empty array
let gaugeHeadTempFV = [];  // Array for head temperature gauges
let gaugeConeTempFV = [];  // Array for cone temperature gauges
let lastPressureValues = [];  // Store last received pressure values
let lastHeadTempValues = [];  // Store last head temperature values
let lastConeTempValues = [];  // Store last cone temperature values

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

  // Store sensor values
  lastPressureValues = myObj.pressure;
  lastHeadTempValues = myObj.headTemp;
  lastConeTempValues = myObj.coneTemp;

  // Get number of tanks from Configuration object
  const newTanksNumber = myObj.Configuration.tanksNumber;
  
  if (TanksNumber !== newTanksNumber) {
    TanksNumber = newTanksNumber;
    document.getElementById('controllerTitle').textContent = 'Pressure Controller';  // Simplified title
    createTankCards(myObj.Configuration);  // Pass configuration
    setTimeout(() => {
        createGauges(myObj.Configuration);  // Pass configuration
        updateGauges(lastPressureValues, lastHeadTempValues, lastConeTempValues);
    }, 100);
  } else {
    updateGauges(lastPressureValues, lastHeadTempValues, lastConeTempValues);
  }
}

// Separate function for updating gauge values
function updateGauges(pressureValues, headTempValues, coneTempValues) {
  if (gaugePressureFV.length > 0) {
    for (let i = 0; i < TanksNumber; i++) {
      if (gaugePressureFV[i] && pressureValues[i] !== undefined) {
        gaugePressureFV[i].value = pressureValues[i];
      }
    }
  }
  
  if (gaugeConeTempFV.length > 0 && coneTempValues) {
    for (let i = 0; i < TanksNumber; i++) {
      if (gaugeConeTempFV[i] && coneTempValues[i] !== undefined) {
        gaugeConeTempFV[i].value = coneTempValues[i];
      }
    }
  }
  
  if (gaugeHeadTempFV.length > 0 && headTempValues) {
    for (let i = 0; i < TanksNumber; i++) {
      if (gaugeHeadTempFV[i] && headTempValues[i] !== undefined) {
        gaugeHeadTempFV[i].value = headTempValues[i];
      }
    }
  }
}

function createGauges(config) {
    gaugePressureFV = [];
    gaugeHeadTempFV = [];
    gaugeConeTempFV = [];
    
    for (let i = 0; i < TanksNumber; i++) {
        // Create pressure gauge only if enabled
        if (config.pressureConfig === 1) {
            const pressureCanvasId = `fv${i + 1}-gauge-pressure`;
            const pressureCanvas = document.getElementById(pressureCanvasId);
            
            if (pressureCanvas) {
                gaugePressureFV[i] = new RadialGauge({
                    renderTo: pressureCanvas,  // Specify the canvas element
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
        
        // Create temperature gauges based on configuration
        if (config.tempConfig === 1 || config.tempConfig === 3) {
          const coneCanvasId = `fv${i + 1}-gauge-cone-temp`;
          const coneCanvas = document.getElementById(coneCanvasId);
          
          if (coneCanvas) {
            gaugeConeTempFV[i] = new LinearGauge({
              renderTo: coneCanvas,
              width: 100,      // Reduced from 120
              height: 250,     // Reduced from 400
              title: "Cone Temp",
              fontTitleSize: 36,
              fontTitleStyle: "bold",
              units: "°C",
              fontUnitsSize: 32,
              minValue: 0,
              maxValue: 40,
              fontNumbersSize: 28,
              colorValueBoxRect: "#049faa",
              colorValueBoxRectEnd: "#049faa",
              colorValueBoxBackground: "#f1fbfc",
              valueDec: 1,
              valueInt: 2,
              fontValueSize: 36,
              majorTicks: ["0","5","10","15","20","25","30","35","40"],
              minorTicks: 4,
              strokeTicks: true,
              highlights: [{
                "from": 23,
                "to": 40,
                "color": "rgba(200, 50, 50, .75)"
              }],
              colorPlate: "#fff",
              colorBarProgress: "#CC2936",
              colorBarProgressEnd: "#049faa",
              borderShadowWidth: 0,
              borders: true,
              borderOuterWidth: 3,
              colorBorderOuter: "#007F80",
              colorBorderOuterEnd: "#007F80",
              borderMiddleWidth: 3,
              colorBorderMiddle: "white",
              colorBorderMiddleEnd: "white",
              borderInnerWidth: 3,
              colorBorderInner: "white",
              colorBorderInnerEnd: "white",
              barWidth: 10,
              needleType: "arrow",
              needleWidth: 2,
              needleCircleSize: 7,
              needleCircleOuter: true,
              needleCircleInner: false,
              animationDuration: 1500,
              animationRule: "linear"
            }).draw();
          }
        }
    
        if (config.tempConfig === 2 || config.tempConfig === 3) {
          const headCanvasId = `fv${i + 1}-gauge-head-temp`;
          const headCanvas = document.getElementById(headCanvasId);
          
          if (headCanvas) {
            gaugeHeadTempFV[i] = new LinearGauge({
              renderTo: headCanvas,  // Fix: was using coneCanvas
              width: 100,      // Reduced from 120
              height: 250,     // Reduced from 400
              title: "Head Temp",
              fontTitleSize: 36,
              fontTitleStyle: "bold",
              units: "°C",
              fontUnitsSize: 32,
              minValue: 0,
              maxValue: 40,
              fontNumbersSize: 28,
              colorValueBoxRect: "#049faa",
              colorValueBoxRectEnd: "#049faa",
              colorValueBoxBackground: "#f1fbfc",
              valueDec: 1,
              valueInt: 2,
              fontValueSize: 36,
              majorTicks: ["0","5","10","15","20","25","30","35","40"],
              minorTicks: 4,
              strokeTicks: true,
              highlights: [{
                "from": 23,
                "to": 40,
                "color": "rgba(200, 50, 50, .75)"
              }],
              colorPlate: "#fff",
              colorBarProgress: "#CC2936",
              colorBarProgressEnd: "#049faa",
              borderShadowWidth: 0,
              borders: true,
              borderOuterWidth: 3,
              colorBorderOuter: "#007F80",
              colorBorderOuterEnd: "#007F80",
              borderMiddleWidth: 3,
              colorBorderMiddle: "white",
              colorBorderMiddleEnd: "white",
              borderInnerWidth: 3,
              colorBorderInner: "white",
              colorBorderInnerEnd: "white",
              barWidth: 10,
              needleType: "arrow",
              needleWidth: 2,
              needleCircleSize: 7,
              needleCircleOuter: true,
              needleCircleInner: false,
              animationDuration: 1500,
              animationRule: "linear"
            }).draw();
          }
        }
    }
}

function createTankCards(config) {
    const cardGrid = document.querySelector('.card-grid');
    cardGrid.innerHTML = '';
    
    for (let i = 0; i < TanksNumber; i++) {
        const tankNum = i + 1;
        const card = document.createElement('div');
        card.className = 'card';
        
        let gaugeHTML = `
            <p class="card-title">FV${tankNum}</p>
            <div class="gauge-container">`;
        
        // Check if any gauges are enabled
        const hasHeadTemp = config.tempConfig === 2 || config.tempConfig === 3;
        const hasConeTemp = config.tempConfig === 1 || config.tempConfig === 3;
        const hasPressure = config.pressureConfig === 1;
        
        if (!hasHeadTemp && !hasConeTemp && !hasPressure) {
            gaugeHTML += `<p class="no-gauges-message">All sensors are disabled. Please enable sensors in Configuration.</p>`;
        } else {
            // Head temperature gauge first
            if (hasHeadTemp) {
                gaugeHTML += `<canvas id="fv${tankNum}-gauge-head-temp" height="200"></canvas>`;
            }
            // Cone temperature gauge second
            if (hasConeTemp) {
                gaugeHTML += `<canvas id="fv${tankNum}-gauge-cone-temp" height="200"></canvas>`;
            }
            // Pressure gauge last
            if (hasPressure) {
                gaugeHTML += `<canvas id="fv${tankNum}-gauge-pressure" height="250"></canvas>`;
            }
        }
        
        gaugeHTML += `
            </div>
            <a href="/fv${tankNum}settings.html">
                <button class="button">FV${tankNum} Settings</button>
            </a>`;
        
        card.innerHTML = gaugeHTML;
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