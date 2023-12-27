



  

#define NODE_COUNT 10 // Number of nodes in the circuit
#define GRID_SIZE 32

struct Connection {
  int fromNode;
  int toNode;
};

enum ComponentType {
  RESISTOR,
  CAPACITOR,
  INDUCTOR,
  DIODE,
  LED,
  TRANSISTOR,
  IC,
  VOLTAGE_REGULATOR,
  TRANSFORMER,
  SWITCH,
  POTENTIOMETER,
  CRYSTAL_OSCILLATOR,
  FUSE,
  RELAY,
  SENSOR
};

struct Component {
  ComponentType type;
  float value; // Value representing specific characteristics (e.g., resistance, capacitance, etc.)
};

Connection connections[NODE_COUNT]; // Array to hold connections
Component components[NODE_COUNT];  // Array to hold components
int Components[GRID_SIZE][GRID_SIZE]; // Represents components in the grid

// List of circuit types
enum CircuitType {
  ANALOG,
  DIGITAL,
  INTEGRATED,
  PCB,
  POWER,
  RF,
  MICROCONTROLLER,
  MIXED_SIGNAL,
  FILTER,
  SENSORS,
  FEEDBACK,
  SWITCHING,
  AMPLIFIER,
  OSCILLATOR
};

void initializeGrid() {
  for (int i = 0; i < GRID_SIZE; ++i) {
    for (int j = 0; j < GRID_SIZE; ++j) {
      Components[i][j] = 0; // Set initial value to zero
    }
  }
}

void setup() {
  Serial.begin(9600); // Initialize serial communication
  initializeGrid();

  randomSeed(analogRead(0)); // Seed the random number generator

  // Generate random connections between nodes
  for (int i = 0; i < NODE_COUNT; ++i) {
    connections[i].fromNode = random(NODE_COUNT);
    connections[i].toNode = random(NODE_COUNT);
  }

  // Generate random components with values and types based on descriptions
  for (int i = 0; i < NODE_COUNT; ++i) {
    switch (random(16)) { // Randomly assign a component type
      case RESISTOR:
        components[i].type = RESISTOR;
        components[i].value = random(10, 10000); // Random resistance value between 10 Ohms and 10 kOhms
        break;
      case CAPACITOR:
        components[i].type = CAPACITOR;
        components[i].value = random(1, 100); // Random capacitance value between 1 picofarad and 100 picofarads
        break;
      // Add cases for other component types similarly...


      case INDUCTOR:
        components[i].type = INDUCTOR;
        components[i].value = random(10, 10000); // Random resistance value between 10 Ohms and 10 kOhms
        break;
      case DIODE:
        components[i].type = DIODE;
        components[i].value = random(1, 100); // Random capacitance value between 1 picofarad and 100 picofarads
        break;



              case TRANSISTOR:
        components[i].type = TRANSISTOR;
        components[i].value = random(10, 10000); // Random resistance value between 10 Ohms and 10 kOhms
        break;
      case TRANSFORMER:
        components[i].type = TRANSFORMER;
        components[i].value = random(1, 100); // Random capacitance value between 1 picofarad and 100 picofarads
        break;



      case VOLTAGE_REGULATOR:
        components[i].type = VOLTAGE_REGULATOR;
        components[i].value = random(10, 10000); // Random resistance value between 10 Ohms and 10 kOhms
        break;
      case SWITCH:
        components[i].type = SWITCH;
        components[i].value = random(1, 100); // Random capacitance value between 1 picofarad and 100 picofarads
        break;




      case CRYSTAL_OSCILLATOR:
        components[i].type = CRYSTAL_OSCILLATOR;
        components[i].value = random(10, 10000); // Random resistance value between 10 Ohms and 10 kOhms
        break;
      case FUSE:
        components[i].type = FUSE;
        components[i].value = random(1, 100); // Random capacitance value between 1 picofarad and 100 picofarads
        break;





              case IC:
        components[i].type = IC;
        components[i].value = random(10, 10000); // Random resistance value between 10 Ohms and 10 kOhms
        break;
      case SENSOR:
        components[i].type = SENSOR;
        components[i].value = random(1, 100); // Random capacitance value between 1 picofarad and 100 picofarads
        break;




              case RELAY:
        components[i].type = RELAY;
        components[i].value = random(10, 10000); // Random resistance value between 10 Ohms and 10 kOhms
        break;
    
        



    }
  }

  // Print the generated connections and components
  Serial.println("Generated Connections:");
  for (int i = 0; i < NODE_COUNT; ++i) {
    Serial.print("Connection ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(connections[i].fromNode);
    Serial.print(" -> ");
    Serial.println(connections[i].toNode);
  }

  Serial.println("\nGenerated Components:");
  for (int i = 0; i < NODE_COUNT; ++i) {
    Serial.print("Component ");
    Serial.print(i);
    Serial.print(": Type=");
    switch (components[i].type) {
      case RESISTOR:
        Serial.print("RESISTOR");
        break;
      case CAPACITOR:
        Serial.print("CAPACITOR");
        break;
      // Add cases for other component types similarly...
      case INDUCTOR:
        Serial.print("INDUCTOR");
        break;
      case DIODE:
        Serial.print("DIODE");
        break;

      case TRANSISTOR:
        Serial.print("TRANSISTOR");
        break;
      case TRANSFORMER:
        Serial.print("TRANSFORMER");
        break;


      case VOLTAGE_REGULATOR:
        Serial.print("VOLTAGE_REGULATOR");
        break;
      case SWITCH:
        Serial.print("SWITCH");
        break;

      case CRYSTAL_OSCILLATOR:
        Serial.print("CRYSTAL_OSCILLATOR");
        break;
      case FUSE:
        Serial.print("FUSE");
        break;

      case IC:
        Serial.print("IC");
        break;
      case RELAY:
        Serial.print("RELAY");
        break;



    }
    Serial.print(", Value=");
    Serial.println(components[i].value);
  }
}

void loop() {
  if (Serial.available() > 0) {
    String userInput = Serial.readStringUntil('\n'); // Read user input
    userInput.trim(); // Remove leading/trailing whitespace

    if (userInput.equals("hi")) {
      Serial.println("Bot: Hello there!");
    } else if (userInput.equals("how are you?")) {
      Serial.println("Bot: I'm good, thank you!");
    } else if (userInput.equals("bye")) {
      Serial.println("Bot: Goodbye!");
    } else {
      Serial.println("Bot: I'm not sure how to respond to that.");
    }
  }

  delay(1000); // Adjust delay as needed

  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // Read command from serial

    // Process the command
    if (command.startsWith("add")) {
      // Example: "add 5 10"
      int x = command.substring(4, 6).toInt();
      int y = command.substring(7).toInt();

      // Check if indices are within bounds
      if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
        Components[x][y]++;
      }
    } else if (command.startsWith("subtract")) {
      // Example: "subtract 5 10"
      int x = command.substring(9, 11).toInt();
      int y = command.substring(12).toInt();

      // Check if indices are within bounds
      if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
        Components[x][y]--;
      }
    } else if (command.startsWith("select")) {
      // Example: "select 5 10"
      int x = command.substring(7, 9).toInt();
      int y = command.substring(10).toInt();

      // Check if indices are within bounds
      if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
        // Process the selected point (e.g., perform a specific action, print value, etc.)
        Serial.print("Selected Point [");
        Serial.print(x);
        Serial.print(",");
        Serial.print(y);
      }
  }
}


   Serial.print("]: ");
        Serial.println(Components[x][y]);
      }
   
