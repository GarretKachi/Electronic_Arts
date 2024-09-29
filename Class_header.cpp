// mood_based_interactions.h
#ifndef MOOD_BASED_INTERACTIONS_H
#define MOOD_BASED_INTERACTIONS_H

#include <string>
#include <vector>

// Forward declarations
class Mood;
class Interaction;
class Relationship;
class Effect;
class Sim;

class Sim {
public:
    // Instance variables
    std::string name;
    int age;
    Mood* currentMood;
    std::vector<Relationship*> relationshipList;

    // Methods
    void interact(Sim* otherSim);
    void updateMood(Mood* newMood);
    void performInteraction(Interaction* interaction);
};

class Mood {
public:
    // Instance variables
    std::string type;
    int intensity;  // Intensity of the mood (scale)
    int duration;   // Duration of the mood

    // Methods
    void decay();       // Decreases mood over time
    void intensify();   // Increases the intensity of the mood
    void weaken();      // Weakens the mood
};

class Interaction {
public:
    // Instance variables
    std::string type;   // Type of interaction (friendly, mean, etc.)
    Mood* requiredMood; // Mood required to trigger the interaction
    Effect* effect;     // The effect of the interaction

    // Methods
    void trigger(Sim* sim, Sim* targetSim);  // Triggers the interaction
    void applyEffect(Sim* sim);              // Applies the effect of the interaction
};

class EmotionBasedInteraction : public Interaction {
public:
    // Instance variables
    Mood* moodRequired;  // Mood required to perform the interaction

    // Methods
    void triggerBasedOnMood(Sim* sim);  // Trigger interaction based on Sim's mood
};

class Relationship {
public:
    // Instance variables
    Sim* simA;  // First Sim in the relationship
    Sim* simB;  // Second Sim in the relationship
    int friendshipLevel;  // Friendship level between the Sims
    int romanceLevel;     // Romance level between the Sims
    std::string relationshipStatus;  // Status of the relationship (growing, fading, etc.)

    // Methods
    void updateLevel(int delta);        // Updates the relationship level
    void changeStatus(std::string status);  // Changes the relationship status
};

class InteractionMenu {
public:
    // Instance variables
    std::vector<Interaction*> availableInteractions;

    // Methods
    void showForSim(Sim* sim);              // Displays available interactions for the Sim
    void filterInteractionsByMood(Mood* mood);  // Filters interactions based on mood
};

class World {
public:
    // Instance variables
    std::vector<Sim*> simList;  // List of all Sims in the world

    // Methods
    void updateAllMoods();                         // Updates the mood for all Sims
    void handleInteractions(Sim* simA, Sim* simB); // Handles interactions between Sims
};

class Effect {
public:
    // Instance variables
    int targetMoodChange;     // Change in mood due to interaction
    int relationshipChange;   // Change in relationship due to interaction

    // Methods
    void apply(Sim* simA, Sim* simB);  // Applies the effect to the Sims
};

#endif // MOOD_BASED_INTERACTIONS_H
