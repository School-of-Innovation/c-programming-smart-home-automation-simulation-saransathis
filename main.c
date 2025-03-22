#include <stdio.h>

#define MAX_ROOMS 5  // Max number of rooms

// Global arrays (limited to function scope only)
int lights[MAX_ROOMS]; // 0: OFF, 1: ON
int temperatures[MAX_ROOMS]; // Stores temperature
int motionSensors[MAX_ROOMS]; // 0: No motion, 1: Motion detected
int securityLocks[MAX_ROOMS]; // 0: Unlocked, 1: Locked

// Function prototypes
void initializeSystem(int rooms);
void displayMenu();
void controlLights(int rooms);
void readTemperature(int rooms);
void detectMotion(int rooms);
void securitySystem(int rooms);
void analyzeHouseStatus(int rooms);

int main() {
    int rooms;
    printf("Enter number of rooms (Max %d): ", MAX_ROOMS);
    scanf("%d", &rooms);
    if (rooms > MAX_ROOMS || rooms <= 0) {
        printf("Invalid number of rooms. Exiting...\n");
        return 1;
    }
    
    initializeSystem(rooms);
    
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                controlLights(rooms);
                break;
            case 2:
                readTemperature(rooms);
                break;
            case 3:
                detectMotion(rooms);
                break;
            case 4:
                securitySystem(rooms);
                break;
            case 5:
                analyzeHouseStatus(rooms);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}

void initializeSystem(int rooms) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;
        temperatures[i] = 22 + (i % 5); // Random temperatures between 22-26
        motionSensors[i] = 0;
        securityLocks[i] = 1;
    }
    printf("System initialized successfully!\n");
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

void controlLights(int rooms) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);
    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }
    lights[room - 1] = !lights[room - 1];
    printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
}

void readTemperature(int rooms) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", rooms);
    scanf("%d", &room);
    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }
    printf("Room %d Temperature: %d°C\n", room, temperatures[room - 1]);
}

void detectMotion(int rooms) {
    int room;
    printf("Enter room number to check motion sensor (1-%d): ", rooms);
    scanf("%d", &room);
    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }
    printf("Motion in Room %d: %s\n", room, motionSensors[room - 1] ? "Detected" : "Not Detected");
}

void securitySystem(int rooms) {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", rooms);
    scanf("%d", &room);
    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }
    securityLocks[room - 1] = !securityLocks[room - 1];
    printf("Room %d Security Lock is now %s.\n", room, securityLocks[room - 1] ? "Locked" : "Unlocked");
}

void analyzeHouseStatus(int rooms) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("- Room %d: Light %s, Temp %d°C, Motion %s, %s\n", i + 1,
               lights[i] ? "ON" : "OFF", temperatures[i],
               motionSensors[i] ? "Detected" : "No Motion",
               securityLocks[i] ? "Locked" : "Unlocked");
    }
}
