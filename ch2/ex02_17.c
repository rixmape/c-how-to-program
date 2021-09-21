// Calculate final velocity and distance traversed

#include <stdio.h>

int main(void)
{
    float initial_velocity, time, acceleration;

    printf("%s", "Initial velocity: ");
    scanf("%f", &initial_velocity);

    printf("%s", "Time elapsed: ");
    scanf("%f", &time);

    printf("%s", "Acceleration: ");
    scanf("%f", &acceleration);

    float final_velocity = initial_velocity + acceleration * time;

    float distance = initial_velocity * time
                    + 0.5 * (acceleration * (time * time));

    printf("\nFinal velocity: %.2f\n", final_velocity);
    printf("Distance traversed: %.2f", distance);

}