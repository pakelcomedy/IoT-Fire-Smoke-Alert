// script.js

const statusEl   = document.getElementById("status");
const valueEl    = document.getElementById("sensorValue");
const alertEl    = document.getElementById("alertStatus");
const buzzerBtn  = document.getElementById("buzzerBtn");
let   buzzerOn   = false;

// Base URL = wherever this page is served
const API_BASE = `${window.location.protocol}//${window.location.host}`;

async function updateStatus() {
  try {
    const res  = await fetch(`${API_BASE}/status`);
    if (!res.ok) throw new Error(res.status);
    const data = await res.json();

    // Update UI
    valueEl.textContent = data.smoke_raw;
    alertEl.textContent = data.alert ? "🔥 Danger" : "✅ Normal";

    if (data.alert) {
      statusEl.textContent = "🔥 ALERT!";
      statusEl.classList.replace("safe", "danger");
    } else {
      statusEl.textContent = "✅ Safe";
      statusEl.classList.replace("danger", "safe");
    }
  } catch (err) {
    console.error("Status fetch error:", err);
    statusEl.textContent = "⚠️ Error";
    statusEl.classList.remove("safe", "danger");
  }
}

// Toggle buzzer on/off
buzzerBtn.addEventListener("click", async () => {
  buzzerOn = !buzzerOn;
  try {
    const res = await fetch(`${API_BASE}/buzzer`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ on: buzzerOn })
    });
    if (!res.ok) throw new Error(res.status);
    buzzerBtn.textContent = buzzerOn
      ? "🔕 Deactivate Buzzer"
      : "🔔 Activate Buzzer";
  } catch (err) {
    console.error("Buzzer toggle error:", err);
  }
});

// Kick off
setInterval(updateStatus, 3000);
updateStatus();
