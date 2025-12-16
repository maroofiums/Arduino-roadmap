import os

# Base directory where you want to create the roadmap
base_dir = "Arduino_Roadmap"

# Roadmap structure
roadmap = {
    "Week 1 - Arduino Basics & Digital I/O": [
        "Arduino IDE & Blink",
        "Digital Input (Button)",
        "Servo Motor Basics",
        "DHT11 Sensor",
        "HC-SR04 Ultrasonic Sensor",
        "Mini Project",
        "Revision & Notes"
    ],
    "Week 2 - Arduino Analog & Advanced I/O": [
        "Analog Input",
        "Multiple LEDs",
        "Button + Servo",
        "Sensor + Output Logic",
        "HC-SR04 + Servo",
        "Mini Project",
        "Revision"
    ],
    "Week 3 - ESP32 Basics & IoT": [
        "ESP32 Blink & Pins",
        "WiFi Connection",
        "HTTP GET Request",
        "DHT11 → Cloud",
        "Remote Control",
        "IoT Mini Project",
        "Revision & Notes"
    ],
    "Week 4 - Advanced IoT & Mini Projects": [
        "Multiple Sensors",
        "Threshold Alerts",
        "ESP32 Web Server",
        "Remote Control + Sensor",
        "MQTT Introduction",
        "Mini IoT Project",
        "Revision & Notes"
    ]
}

# Create folders and files
for week, days in roadmap.items():
    week_path = os.path.join(base_dir, week)
    os.makedirs(week_path, exist_ok=True)
    for i, day in enumerate(days, start=1):
        day_folder = os.path.join(week_path, f"Day{i} - {day}")
        os.makedirs(day_folder, exist_ok=True)

        # Create code.ino file
        code_file_path = os.path.join(day_folder, "code.ino")
        with open(code_file_path, "w", encoding="utf-8") as f:
            f.write(f"// {day} - Arduino code\n\nvoid setup() {{\n  // TODO: add setup code\n}}\n\nvoid loop() {{\n  // TODO: add loop code\n}}\n")

        # Create notes.md file
        notes_file_path = os.path.join(day_folder, "notes.md")
        with open(notes_file_path, "w", encoding="utf-8") as f:
            f.write(f"# {day}\n\n## Goal\n\nWrite notes about {day} here.\n\n## Concepts / Observations\n\n- \n- \n- \n")

print(f"Arduino roadmap folders and files created successfully in '{base_dir}'!")
