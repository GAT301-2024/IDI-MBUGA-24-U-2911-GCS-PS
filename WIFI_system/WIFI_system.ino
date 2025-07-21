#include <WiFi.h>

const char* ssid = "IBO";
const char* password = "84891024";

#define LED1 21
#define LED2 20
#define LED3 1

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            
            client.println("<!DOCTYPE html><html><head>");
            client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link href='https://fonts.googleapis.com/css2?family=Poppins:wght@400;600&display=swap' rel='stylesheet'>");
            client.println("<style>");
            client.println("body { font-family: 'Poppins', sans-serif; margin: 0; padding: 0; background: #faf5ff; color: #333; }");
            client.println(".header { background: linear-gradient(135deg, #7b2cbf 0%, #5a189a 100%); color: white; padding: 25px; text-align: center; border-radius: 0 0 20px 20px; box-shadow: 0 4px 20px rgba(123, 44, 191, 0.2); }");
            client.println("h1 { margin: 0; font-size: 2.2rem; font-weight: 600; letter-spacing: 1px; }");
            client.println("h2 { margin: 5px 0 0; font-size: 1.2rem; font-weight: 400; opacity: 0.9; }");
            client.println(".container { max-width: 800px; margin: 30px auto; padding: 0 20px; }");
            client.println(".card { background: white; border-radius: 15px; padding: 25px; margin-bottom: 30px; box-shadow: 0 5px 15px rgba(0,0,0,0.05); transition: transform 0.3s; }");
            client.println(".card:hover { transform: translateY(-5px); }");
            client.println(".btn { display: inline-block; padding: 12px 28px; margin: 8px 5px; border: none; border-radius: 50px; font-family: 'Poppins', sans-serif; font-size: 1rem; font-weight: 600; cursor: pointer; transition: all 0.3s; box-shadow: 0 4px 10px rgba(0,0,0,0.1); }");
            client.println(".btn-on { background: #9d4edd; color: white; }");
            client.println(".btn-on:hover { background: #7b2cbf; box-shadow: 0 6px 15px rgba(157, 78, 221, 0.3); }");
            client.println(".btn-off { background: #e0aaff; color: #5a189a; }");
            client.println(".btn-off:hover { background: #c77dff; box-shadow: 0 6px 15px rgba(224, 170, 255, 0.3); }");
            client.println(".led-status { display: inline-block; width: 80px; text-align: center; margin-left: 10px; font-weight: 600; }");
            client.println(".on { color: #9d4edd; }");
            client.println(".off { color: #adb5bd; }");
            client.println("table { width: 100%; border-collapse: separate; border-spacing: 0; margin-top: 20px; }");
            client.println("th { background: #7b2cbf; color: white; padding: 15px; text-align: left; font-weight: 600; }");
            client.println("td { padding: 15px; border-bottom: 1px solid #f1e9ff; }");
            client.println("tr:nth-child(even) { background: #f9f0ff; }");
            client.println("tr:hover { background: #f3e5ff; }");
            client.println("</style></head>");
            
            client.println("<body>");
            client.println("<div class=\"header\">");
            client.println("<h1>NOVA TEAM</h1>");
            client.println("<h2>ESP32 WIFI Light System</h2>");
            client.println("</div>");
            
            client.println("<div class=\"container\">");
            client.println("<div class=\"card\">");
            client.println("<h3>Light Control Panel</h3>");
            
            // LED 1 Controls
            client.println("<p>LED 1 - <span class=\"led-status " + String(digitalRead(LED1) ? "on\">ON" : "off\">OFF") + "</span></p>");
            client.println("<a href=\"/led1/on\"><button class=\"btn btn-on\">TURN ON</button></a>");
            client.println("<a href=\"/led1/off\"><button class=\"btn btn-off\">TURN OFF</button></a>");
            
            // LED 2 Controls
            client.println("<p>LED 2 - <span class=\"led-status " + String(digitalRead(LED2) ? "on\">ON" : "off\">OFF") + "</span></p>");
            client.println("<a href=\"/led2/on\"><button class=\"btn btn-on\">TURN ON</button></a>");
            client.println("<a href=\"/led2/off\"><button class=\"btn btn-off\">TURN OFF</button></a>");
            
            // LED 3 Controls
            client.println("<p>LED 3 - <span class=\"led-status " + String(digitalRead(LED3) ? "on\">ON" : "off\">OFF") + "</span></p>");
            client.println("<a href=\"/led3/on\"><button class=\"btn btn-on\">TURN ON</button></a>");
            client.println("<a href=\"/led3/off\"><button class=\"btn btn-off\">TURN OFF</button></a>");
            client.println("</div>");
            
            client.println("<div class=\"card\">");
            client.println("<h3>Team Members</h3>");
            client.println("<table>");
            client.println("<tr><th>Name</th><th>Registration Number</th></tr>");
            client.println("<tr><td>Ibolit Emmanuel</td><td>24/U/0304/GIM</td></tr>");
            client.println("<tr><td>Mbuga Idi</td><td>24/U/2911/GCS/PS</td></tr>");
            client.println("<tr><td>Murungi Darlison</td><td>24/U/3000/GCS/PS</td></tr>");
            client.println("<tr><td>Mwesigwa Disan</td><td>24/U/0067/GIM</td></tr>");
            client.println("<tr><td>Twesiime David Paul</td><td>24/U/4191/GCS/PS</td></tr>");
            client.println("<tr><td>Kutto Benson</td><td>24/U/2675/GIW/PS</td></tr>");
            client.println("<tr><td>Ojera Allan</td><td>24/U/3510/GCS/PS</td></tr>");
            client.println("<tr><td>Khanzila Hellen</td><td>24/U/4885/GIM</td></tr>");
            client.println("<tr><td>Barasa Mercy</td><td>24/U/4881/GIM</td></tr>");
            client.println("<tr><td>Adikin Mary Synthar</td><td>24/U/1285/GCS/Ps</td></tr>");
            client.println("</table>");
            client.println("</div>");
            client.println("</div>");
            client.println("<footer>");
            client.println("IDI MBUGA TEAM_NOVAH ESP32 WIFI light system 2025");
            client.println("</footer></body></html>");
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }

        // Handle LED control requests
        if (currentLine.endsWith("GET /led1/on")) digitalWrite(LED1, HIGH);
        else if (currentLine.endsWith("GET /led1/off")) digitalWrite(LED1, LOW);
        else if (currentLine.endsWith("GET /led2/on")) digitalWrite(LED2, HIGH);
        else if (currentLine.endsWith("GET /led2/off")) digitalWrite(LED2, LOW);
        else if (currentLine.endsWith("GET /led3/on")) digitalWrite(LED3, HIGH);
        else if (currentLine.endsWith("GET /led3/off")) digitalWrite(LED3, LOW);
      }
    }
    client.stop();
  }
}