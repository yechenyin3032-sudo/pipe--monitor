<!DOCTYPE html>
<html lang="zh-TW">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>管路監測真實連線版</title>
    <style>
        :root {
            --bg-color: #f0f2f5;
            --card-bg: #ffffff;
            --text-main: #1c1e21;
            --text-sub: #606770;
            --primary-blue: #2e69ff;
            --danger-red: #fb4b4b;
            --warning-orange: #fca130;
            --success-green: #2ecc71;
        }

        body {
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, sans-serif;
            background-color: var(--bg-color);
            color: var(--text-main);
            margin: 0;
            padding: 20px;
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        .container { width: 100%; max-width: 500px; }

        .card {
            background: var(--card-bg);
            border-radius: 16px;
            padding: 20px;
            box-shadow: 0 4px 12px rgba(0,0,0,0.05);
            margin-bottom: 20px;
        }

        .header { display: flex; flex-direction: column; gap: 10px; margin-bottom: 20px; }
        .ip-config { display: flex; gap: 5px; }
        input { flex: 1; padding: 8px; border-radius: 8px; border: 1px solid #ddd; }
        
        .btn {
            background: var(--primary-blue);
            color: white; border: none; padding: 8px 15px;
            border-radius: 8px; cursor: pointer; font-weight: bold;
        }

        .data-grid { display: grid; grid-template-columns: 1fr 1fr; gap: 15px; }
        .data-item { background: #f8f9fa; padding: 15px; border-radius: 12px; }
        .data-label { font-size: 13px; color: var(--text-sub); }
        .data-value { font-size: 20px; font-weight: bold; margin-top: 5px; }

        .logic-list { list-style: none; padding: 0; margin: 0; }
        .logic-list li {
            padding: 10px 0; border-bottom: 1px solid #eee;
            font-size: 14px; display: flex; justify-content: space-between;
        }

        .status-box {
            text-align: center; padding: 20px; border-radius: 12px;
            font-weight: bold; font-size: 18px; border: 1px solid #ddd;
        }
        .status-normal { color: var(--success-green); background: #eafaf1; border-color: var(--success-green); }
        .status-danger { color: var(--danger-red); background: #fdeded; border-color: var(--danger-red); }
        .status-warning { color: var(--warning-orange); background: #fef5e7; border-color: var(--warning-orange); }
    </style>
</head>
<body>

<div class="container">
    <div class="header">
        <h2 style="margin: 0;">🌊 管路監測 Pro (真實連線)</h2>
        <div class="ip-config">
            <input type="text" id="esp-ip" placeholder="請輸入 ESP32 IP (例如 192.168.1.10)">
            <button class="btn" onclick="toggleConnect()" id="btn-connect">開始連線</button>
        </div>
    </div>

    <div class="card">
        <div class="card-title" style="font-weight:600; margin-bottom:10px;">📊 即時量測值</div>
        <div class="data-grid">
            <div class="data-item">
                <div class="data-label">水位高度</div>
                <div id="val-water" class="data-value">-- <span style="font-size:12px">cm</span></div>
            </div>
            <div class="data-item">
                <div class="data-label">理想流速</div>
                <div id="val-flow" class="data-value">-- <span style="font-size:12px">cm/min</span></div>
            </div>
        </div>
    </div>

    <div class="card">
        <div class="card-title" style="font-weight:600; margin-bottom:10px;">⚙️ 判定邏輯</div>
        <ul class="logic-list">
            <li><span>總高設定 (硬體)</span> <strong>50 cm</strong></li>
            <li><span>堵塞警示</span> <span style="color:var(--danger-red)">流速 < 4800 & 水位 ≥ 16.6</span></li>
            <li><span>湍急警示</span> <span style="color:var(--warning-orange)">流速 > 18000</span></li>
        </ul>
    </div>

    <div id="status-display" class="status-box">尚未連線</div>
</div>

<script>
    let timer = null;
    const TOTAL_HEIGHT = 50; // 配合你 Arduino 的 TANK_HEIGHT 0.5m

    async function fetchData() {
        const ip = document.getElementById('esp-ip').value;
        if (!ip) return;

        try {
            // 向 ESP32 請求 JSON 資料
            const response = await fetch(`http://${ip}/data`);
            const data = await response.json();

            // 單位換算：Arduino 傳出的是 m/s，我們要換算成 cm/min
            // 1 m/s = 6000 cm/min
            const waterCm = data.waterLevel;
            const flowCmMin = data.flowRate * 6000;

            // 更新 UI
            document.getElementById('val-water').innerHTML = `${waterCm.toFixed(1)} <span style="font-size:12px">cm</span>`;
            document.getElementById('val-flow').innerHTML = `${Math.floor(flowCmMin)} <span style="font-size:12px">cm/min</span>`;

            // 判斷邏輯
            const statusBox = document.getElementById('status-display');
            if (flowCmMin < 4800 && waterCm >= (TOTAL_HEIGHT / 3)) {
                statusBox.innerText = "❌ 偵測到管路堵塞！";
                statusBox.className = "status-box status-danger";
            } else if (flowCmMin > 18000) {
                statusBox.innerText = "⚠️ 注意：水流過於湍急";
                statusBox.className = "status-box status-warning";
            } else {
                statusBox.innerText = "✅ 系統運作正常";
                statusBox.className = "status-box status-normal";
            }

        } catch (error) {
            console.error("連線失敗:", error);
            document.getElementById('status-display').innerText = "連線失敗，請檢查 IP 或網路";
        }
    }

    function toggleConnect() {
        const btn = document.getElementById('btn-connect');
        if (timer) {
            clearInterval(timer);
            timer = null;
            btn.innerText = "開始連線";
            document.getElementById('status-display').innerText = "已停止連線";
        } else {
            fetchData();
            timer = setInterval(fetchData, 3000); // 每 3 秒更新一次
            btn.innerText = "停止連線";
        }
    }
</script>

</body>
</html>
