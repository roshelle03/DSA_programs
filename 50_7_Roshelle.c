#include <stdio.h>

// Define the time_struct structure
struct time_struct {
    int hour;
    int minute;
    int second;
};

// Function to input new time
void inputTime(struct time_struct *time) {
    printf("Enter hour: ");
    scanf("%d", &time->hour);
    printf("Enter minute: ");
    scanf("%d", &time->minute);
    printf("Enter second: ");
    scanf("%d", &time->second);
}

// Function to display the time
void displayTime(const struct time_struct *time) {
    printf("Time: %02d:%02d:%02d\n", time->hour, time->minute, time->second);
}

// Function to update the time by one second
void updateTime(struct time_struct *time) {
    // Increment seconds
    time->second++;

    // Check for rollover to the next minute
    if (time->second == 60) {
        time->second = 0;
        time->minute++;

        // Check for rollover to the next hour
        if (time->minute == 60) {
            time->minute = 0;
            time->hour++;

            // Check for rollover to the next day (24 hours)
            if (time->hour == 24) {
                time->hour = 0;
            }
        }
    }
}

int main() {
    struct time_struct currentTime;

    printf("1. Input new time\n");
    printf("2. Display the time\n");
    printf("3. Update the time by one second\n");
    printf("4. Quit\n");

    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputTime(&currentTime);
                break;
            case 2:
                displayTime(&currentTime);
                break;
            case 3:
                updateTime(&currentTime);
                printf("Time updated by one second.\n");
                break;
            case 4:
                printf("Quitting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
