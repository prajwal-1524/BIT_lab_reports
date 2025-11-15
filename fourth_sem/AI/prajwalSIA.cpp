#include <stdio.h>

// Function to simulate the percept (environment input)
int getTemperature() {
    int temp;
    printf("Enter current temperature: ");
    scanf("%d", &temp);
    return temp;
}

// Function to decide action based on percept
char* agentDecision(int temperature) {
    if (temperature > 30)
        return "Turn ON fan";
    else
        return "Turn OFF fan";
}

// Function to perform the action
void performAction(const char* action) {
    printf("Action: %s\n", action);
}

int main() {
    int temperature = getTemperature();       // Perceive
    char* action = agentDecision(temperature); // Decide
    performAction(action);                    // Act
    return 0;
}


