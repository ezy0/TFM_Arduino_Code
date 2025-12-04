String webpage() {
  String page = R"rawliteral(
    <!DOCTYPE html>
    <html lang="es">
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Control LED</title>
      <style>
        * { margin: 0; padding: 0; box-sizing: border-box; }
        body {
          font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', sans-serif;
          display: flex;
          justify-content: center;
          align-items: center;
          min-height: 100vh;
          background: linear-gradient(135deg, #2c3e50 0%, #1a1a1a 100%);
        }
        .container {
          background: linear-gradient(145deg, #3a3a3a, #2a2a2a);
          padding: 50px;
          border-radius: 25px;
          box-shadow: 0 20px 60px rgba(0,0,0,0.6),
                      inset 0 1px 0 rgba(255,255,255,0.1);
          text-align: center;
        }
        h1 {
          color: #e0e0e0;
          margin-bottom: 40px;
          font-size: 28px;
          text-shadow: 0 2px 4px rgba(0,0,0,0.5);
        }
        .switch {
          position: relative;
          display: inline-block;
          width: 120px;
          height: 60px;
        }
        .switch input { display: none; }
        .slider {
          position: absolute;
          cursor: pointer;
          top: 0; left: 0; right: 0; bottom: 0;
          background: linear-gradient(145deg, #1a1a1a, #0d0d0d);
          transition: .4s;
          border-radius: 60px;
          box-shadow: inset 0 3px 8px rgba(0,0,0,0.6),
                      0 2px 4px rgba(0,0,0,0.3);
        }
        .slider:before {
          position: absolute;
          content: "";
          height: 46px;
          width: 46px;
          left: 7px;
          bottom: 7px;
          background: linear-gradient(145deg, #4a4a4a, #3a3a3a);
          transition: .4s;
          border-radius: 50%;
          box-shadow: 0 3px 8px rgba(0,0,0,0.5),
                      inset 0 1px 0 rgba(255,255,255,0.2);
        }
        input:checked + .slider {
          background: linear-gradient(145deg, #4CAF50, #388E3C);
          box-shadow: inset 0 3px 8px rgba(0,0,0,0.4),
                      0 0 15px rgba(76, 175, 80, 0.4);
        }
        input:checked + .slider:before {
          transform: translateX(60px);
          background: linear-gradient(145deg, #5a5a5a, #4a4a4a);
        }
      </style>
    </head>
    <body>
      <div class="container">
        <h1>Controlador de Luz</h1>
        <label class="switch">
          <input type="checkbox" id="lightSwitch" onchange="fetch('/light?state=' + (this.checked ? 1 : 0))">
          <span class="slider"></span>
        </label>
      </div>
    </body>
    </html>
  )rawliteral";
  return page;
}