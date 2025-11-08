import os

base_dir = "Arduino_Projects"

folders = {
    "Week01_Basics": ["Blink_LED", "Button_LED"],
    "Week02_Analog_IO": ["Potentiometer_LED", "Traffic_Light"],
    "Week03_Sensors_Actuators": ["Temp_Fan_Control", "Ultrasonic_Buzzer"],
    "Week04_Serial_Displays": ["Temp_LCD", "Serial_Game"],
    "Week05_Wireless": ["Bluetooth_LED", "WiFi_TempMonitor"],
    "Week06_Advanced_Sensors": ["Smart_Garden", "Motion_Alarm"],
    "Week07_Robotics": ["Line_Following_Robot", "Obstacle_Robot"],
    "Week08_Final_Projects": ["IoT_Smart_Home", "Security_System"]
}

sample_code = """\
/*
  Project: {project_name}
  Description: Starter code
*/

void setup() {{
  // Initialize serial communication
  Serial.begin(9600);
}}

void loop() {{
  // Your code here
}}
"""

os.makedirs(base_dir, exist_ok=True)

for week, projects in folders.items():
    week_path = os.path.join(base_dir, week)
    os.makedirs(week_path, exist_ok=True)
    
    for project in projects:
        project_path = os.path.join(week_path, project)
        os.makedirs(project_path, exist_ok=True)
        
        ino_file = os.path.join(project_path, f"{project}.ino")
        with open(ino_file, "w") as f:
            f.write(sample_code.format(project_name=project))

print(f"Arduino project structure created successfully in '{base_dir}'!")
