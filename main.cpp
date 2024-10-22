#include <iostream>
#include <string>
using namespace std;

/* walkthrough: just copy paste these into the terminal and they will play the game for you
oaooo Puff yh fcfo phlo sgoogwo
fffo fffo phlo phlo sgoogwo
flfo phlo phlo phlo sgoogwo
vktststlg fsfo pkoo sgoogwo
flfo flfo flfo pkoo sgoogwo
*/

// TODO:
// test more stuff
// replace these params before passing

#define PARAMS \
    bool toysOwned[], \
    int foodsOwned[], \
    int& happiness, \
    int& nutrition, \
    int& energy, \
    int& health, \
    string& name, \
    int& money, \
    int& day, \
    int& hour, \
    int& ending

#define ARGS \
    toysOwned, \
    foodsOwned, \
    happiness, \
    nutrition, \
    energy, \
    health, \
    name, \
    money, \
    day, \
    hour, \
    ending

// TODO: char getChar(char& choice);
bool confirm(string text);
void prompt(char expected, string text);
void pause();

void findPet(PARAMS);
void namePet(PARAMS);
void menu(PARAMS);

int petScore(PARAMS);
void remarkAboutPet(PARAMS);

void check(PARAMS);
void checkPet(PARAMS);
void checkCalendar(PARAMS);
void showTime(int hour);
void checkToys(PARAMS);
void checkFood(PARAMS);

void play(PARAMS);
void playWith(PARAMS, int id);
void feed(PARAMS);
void feedWith(PARAMS, int id);

void passTime(int & day, int & hour, int amount);
void sleep(PARAMS);
void statCheck(string statName, int stat);
void statChange(string statName, int & stat, int change, int cap);
void visitStore(PARAMS);

void quit(PARAMS);

void playEnding(PARAMS);
void error();

// endings
enum Ending {
    Ongoing,
    GiveUp,
    Sick,
    Hungry,
    Unhappy,
    NewYear,
    Joyride,
};

// gameplay constants
const int INCOME = 100;
const int MIDNIGHT = 0;
const int TIME_WAKE = 6;
const int STORE_CLOSING = 12 + 7;
const int CLOCK_OUT = 12 + 6;
const int DAY_LIMIT = 31;

// other constants
const int INTRO_LEAVE_HAPPINESS_COST = 10;
const int INTRO_LEAVE_ENERGY_COST = 10;
const int UNLIMITED = 0;
const int LOW_MONEY = 50;
const int DATE_LATE_GAME = 7 * 4;
const int MANY_ITEMS_BOUGHT = 4;

// pet related stats
const int GREETING_SCORE_MIN = 80;
const int MAX_STAT = 100;
const int MAX_NUTRITION_OVERFLOW = 20;

// when sleeping
const int HEALTHY_HAPPINESS_MIN = 50;
const int HEALTHY_NUTRITION_MIN = 50;
const int HEALTHY_ENERGY_MAX = 50;
const int HEALTHY_BEDTIME_MIN = 12 + 6;
const int HEALTHY_BEDTIME_MAX = 12 + 10;
const int HEALTH_BONUS = 5;
const int SLEEP_HAPPINESS_COST = 20;
const int SLEEP_NUTRITION_COST = 10;
const int SLEEP_ENERGY_BONUS = 10;

// toy data
enum Toy {
    Hand,
    Box,
    Ball,
    Skate,
    Drone,
    Food,
};
const int TOY_COUNT = 5;
const int TOY_COUNT_FULL = 6;

const string TOY_PROMPTS[] = {
    "my [H]and",
    "cardboard bo[X]es",
    "[R]ubber ball",
    "cool s[K]ateboard",
    "super cool [D]rone"
};
const int TOY_PRICES[]           = { 0, 25, 50, 300, 1500};
const int TOY_ENERGY_COSTS[]     = { 5, 10, 10,  15,   25, 5};
const int TOY_HAPPINESS_VALUES[] = {10, 15, 20,  25,   50, 5};

const int PLAY_FOOD_HAPPINESS_MIN = 50;
const int PLAY_FOOD_NUTRITION_MAX = HEALTHY_NUTRITION_MIN;
const int PLAY_FOOD_ENERGY_MIN = 50;

// food data
enum Food {
    Leftover,
    Fish,
    PetFood,
    Chicken,
    Steak,
};
const int FOOD_COUNT = 5;

const string FOOD_PROMPTS[] = {
    "some [L]eftovers from last meal",
    "a piece of [F]ish",
    "a serving of [P]et food",
    "a [C]hicken nugget",
    "a slice of [S]teak"
};
const string FOOD_COUNT_NAMES[] = {
    "Leftover",
    "Fish",
    "Pet Food",
    "Chicken",
    "Steak"
};
const int FOOD_PRICES[]           = { 0, 20, 40, 60, 80}; 
const int FOOD_ENERGY_VALUES[]    = {-5,  0,  5, 10, 15}; 
const int FOOD_NUTRITION_VALUES[] = { 5, 10, 15, 20, 25}; 
const int FOOD_HAPPINESS_VALUES[] = {-5,  0,  5, 10, 15};
const string MONTH = "December";
const int YEAR = 1999;

int main() {
    bool toysOwned[] = {
        true, // hand
        false, // box
        false, // ball
        false, // skate
        false // drone
    };
    int foodsOwned[] = {1,
        2, // leftover
        0, // fish
        1, // pet food
        0, // chicken
        0 // steak
    };

    // pet stats
    int happiness = 30;
    int nutrition = 30;
    int energy = 30;
    int health = 30;
    string name = "[unnamed creature]";

    // other stats
    int money = 200;
    int day = 1;
    int hour = 12 + 8;
    int ending = Ongoing;

    findPet(ARGS);
    while (ending == Ongoing) {
        menu(ARGS);
    }
    playEnding(ARGS);

    return 0;
}

bool confirm(string text) {
    char input;
    while (true) {
        cout << text << endl;
        cout << "> [Y]es" << endl;
        cout << "> [N]o" << endl;
        cout << "> ";
        cin >> input;
        cout << endl;
        switch (input) {
        case 'Y':
        case 'y':
            return true;
            break;

        case 'N':
        case 'n':
            return false;
            break;
        }
    }
}

void prompt(char expected, string text) {
    char input;
    do {
        cout << "> [" << expected << "]" << text << endl;
        cout << "> ";
        cin >> input;
        cout << endl;
    } while (tolower(input) != tolower(expected));
}

void pause() {
    prompt('O', "k");
}

void findPet(PARAMS) {
    char choice;
    bool creatureAdopted = false;

    cout << "Nighttime." << endl;
    cout << "It's been a long week, and our coworkers left early." << endl;
    cout << "Welp, time to go home. Might as well walk." << endl;
    pause();
    cout << "Oh! What's this" << endl;
    cout << "A strange, rotund, perfectly spherical creature..." << endl;

    while (!creatureAdopted) {
        cout << "What will you do with this creature?" << endl;
        cout << "> [A]dopt it" << endl;
        cout << "> [L]eave it" << endl;
        cout << "> ";
        cin >> choice;
        choice = tolower(choice);
        cout << endl;

        switch (choice) {
        case 'a':
            cout << "You hold out your hand onto the ground." << endl;
            pause();
            cout << "It skitters backward. But you stay where you are." << endl;
            cout << "Curious. It's not exactly a cat or a dog. Not even a squirrel or whatever." << endl;
            pause();
            cout << "Hm. Now it's slowly walking toward your hand." << endl;
            cout << "Eventually, it hops on your hand and stays." << endl;
            cout << "It seems to be comfortable with you." << endl;
            pause();
            cout << "Let's give it a name." << endl;

            creatureAdopted = true;
            break;

        case 'l':
            cout << "Well, it's time to head home." << endl;
            cout << "You walk away." << endl;
            pause();
            cout << "There's your house. Just have to pull out your keys, and..." << endl;
            cout << "Huh? Something fluffy is in there." << endl;
            cout << "You pull it out." << endl;
            pause();
            cout << "It's the creature." << endl;
            cout << "..." << endl;
            cout << "Looks like you're stuck with it now." << endl;
            pause();
            cout << "Might as well name it." << endl;

            happiness -= INTRO_LEAVE_HAPPINESS_COST;
            energy -= INTRO_LEAVE_ENERGY_COST;
            creatureAdopted = true;
            break;

        default:
            cout << "[Invalid option, try again]" << endl;
            pause();
            break;
        }
    }
    namePet(ARGS);
}

void namePet(PARAMS) {
    bool sure;
    do {
        name = "[unnamed]";
        cout << "What will you name your pet?" << endl;
        cout << "> ";
        cin >> name;
        cout << endl;
    } while (!confirm("Are you sure you want to call your pet " + name + "? (Can be renamed)"));
    cout << "Alright. Say hello to " << name << "!" << endl;
    prompt('H', "ello!");
}

int petScore(PARAMS) {
    return (happiness + nutrition + energy + health) / 40;
}

void remarkAboutPet(PARAMS) {
    int score = petScore(ARGS);
    const string REMARKS[] = {
        "Listen. ", " deserves better.",
        "Uh, ", " looks a bit sick.",
        "Hm. ", " doesn't look too good.",
        "Hey, looks like ", " needs a little care.",
        "Take care of ", "!",
        "Say hi to ", " again!",
        "Looks like ", " is looking good!",
        "Who is it? It's ", "!",
        "Aww, ", " is so cute.",
        "I just wanna squish ", "..."
    };

    cout << REMARKS[score * 2] << name << REMARKS[score * 2 + 1] << endl;
}

void menu(PARAMS) {
    char choice;

    remarkAboutPet(ARGS);

    // past midnight rolls over to 0
    if (hour < TIME_WAKE) {
        cout << "It's past midnight." << endl;
        cout << "I should sleep." << endl;
        prompt('S', "leep");
        sleep(ARGS);
        return;
    }
    if (energy <= 0) {
        cout << name << " is very tired now." << endl;
        prompt('S', "leep");
        sleep(ARGS);
        return;
    }

    cout << "What would you like to do?" << endl;
    cout << "> [C]heck something" << endl;
    cout << "> [V]isit the Pet Store";
    if (hour > STORE_CLOSING) {
        cout << " (closed)";
    }
    cout << endl;
    cout << "> [R]ename " << name << endl;
    cout << "> [P]lay with " << name << endl;
    cout << "> [F]eed " << name << endl;
    cout << "> [S]leep beside " << name << endl;
    cout << "> [G]ive up" << endl;
    cout << "> ";
    cin >> choice;
    choice = tolower(choice);
    cout << endl;

    switch (choice) {
    case 'c':
        check(ARGS);
        break;

    case 'r':
        namePet(ARGS);
        break;

    case 'v':
        visitStore(ARGS);
        break;

    case 'p':
        play(ARGS);
        break;

    case 'f':
        feed(ARGS);
        break;

    case 's':
        sleep(ARGS);
        break;

    case 'g':
        quit(ARGS);
        break;

    default:
        cout << "[Invalid option, try again]" << endl;
        cout << endl;
        break;
    }
}

void check(PARAMS) {
    char choice;

    while (true) {
        cout << "What would you like to check?" << endl;
        cout << "> [B]ack..." << endl;
        cout << "> [P]et" << endl;
        cout << "> [C]alendar, clock, and wallet" << endl;
        cout << "> [T]oy shelf" << endl;
        cout << "> [F]ood cabinet" << endl;
        cout << "> ";
        cin >> choice;
        choice = tolower(choice);
        cout << endl;

        switch (choice) {
        case 'b':
            return;
            break;

        case 'p':
            checkPet(ARGS);
            break;

        case 'c':
            checkCalendar(ARGS);
            break;

        case 't':
            checkToys(ARGS);
            break;

        case 'f':
            checkFood(ARGS);
            break;

        default:
            cout << "[Invalid option, try again]" << endl;
            break;
        }
        pause();
    }
}

void statCheck(string statName, int stat) {
    cout << statName << "[";
    for (
        int i = MAX_STAT / 20;
        stat >= i || i < MAX_STAT;
        i += MAX_STAT / 10
    ) {
        if (stat >= i) {
            cout << "#";
        } else {
            cout << ".";
        }
    }
    cout << "] (" << stat << "/" << MAX_STAT << ")" << endl;
}

void checkPet(PARAMS) {
    cout << "Alright, let's see how " << name << " is doing..." << endl;
    cout << "Name: " << name << endl;
    statCheck("Happiness: ", happiness);
    statCheck("Nutrition: ", nutrition);
    statCheck("Energy:    ", energy);
    statCheck("Health:    ", health);
}

void checkCalendar(PARAMS) {
    int timeLeft = HEALTHY_BEDTIME_MAX - hour;
    cout << "Let's look at how we're doing..." << endl;

    cout << "Date: " << MONTH << " " << day << ", " << YEAR << endl;
    if (day > DATE_LATE_GAME) {
        cout << "I almost can't believe how long it's been." << endl;
    }

    showTime(hour);
    if (timeLeft < 0) {
        cout << "*Sigh.* It's getting really late. We should've slept earlier." << endl;
    } else if (timeLeft == 0) {
        cout << "It's getting late. We should sleep now." << endl;
    } else if (timeLeft == 1) {
        cout << "I still have 1 hour left with " << name << " tonight." << endl;
        cout << "I'll have to make the most of it." << endl;
    } else {
        cout << "I still have " << timeLeft << " hours with " << name << "." << endl;
    }

    cout << "Pet Budget: PHP " << money << endl;
    if (money < LOW_MONEY) {
        cout << "Uff. Well, all of that money was saved up just for " << name << ", anyway." << endl;
        cout << "I have enough in my real savings account." << endl;
    }
}

void showTime(int hour) {
    bool am = hour < 12;
    int displayHour = hour;
    if (!am) {
        displayHour -= 12;
    }
    if (displayHour == 0) {
        displayHour = 12;
    }

    cout << "Time: " << displayHour;
    if (am) {
        cout << " A.M." << endl;
    } else {
        cout << " P.M." << endl;
    }
}

void checkToys(PARAMS) {
    int toyCount = 0;
    const string TOY_CHECK_MESSAGES[] = {
        "We have some cardboard boxes...",
        "There's a rubber ball...",
        "There's a cool skateboard...",
        "That's a super cool drone..."
    };

    cout << "Let's open the shelf." << endl;
    for (int i = 1; i < TOY_COUNT; i++) {
        if (toysOwned[i]) {
            cout << TOY_CHECK_MESSAGES[i - 1] << endl;
            toyCount++;
        }
    }

    // shouldn't use an array of strings here since name is dynamic
    switch (toyCount) {
    case 0:
        cout << "There's nothing. Maybe I could buy something." << endl;
        cout << "In the meantime, I could just lift " << name << " up with my hands." << endl;
        break;

    case 1:
        cout << "And that's about it." << endl;
        break;

    case 2:
        cout << "I wonder which one I should play with next..." << endl;
        cout << "Wait, these are " << name << "'s toys, not mine!" << endl;
        break;

    case 3:
        cout << "Plenty of entertainment for " << name << "." << endl;
        break;

    case 4:
        cout << "Wow, that's... a lot of stuff I wouldn't buy for myself." << endl;
        break;
    }
}

void checkFood(PARAMS) {
    int foodCount = 0;
    const string TEXT[] = {
        "leftover meal", "s", "from lunch",
        "piece", "s", "of fish",
        "serving", "s", "of pet food",
        "chicken nugget", "s", "",
        "slice", "s", "of steak"
    };

    cout << "Let's look at our food in the fridge." << endl;
    for (int i = 0; i < FOOD_COUNT; i++) {
        if (foodsOwned[i] > 0) {
            cout << "We have " << foodsOwned[i] << " " << TEXT[i * 3];
            if (foodsOwned[i] != 1) {
                cout << TEXT[i * 3 + 1];
            }
            cout << " " << TEXT[i * 3 + 2] << "..." << endl;
            foodCount += foodsOwned[i];
        }
    }

    // operates over ranges, shouldn't use switch case
    if (foodCount == 1) {
        cout << "There's nothing good here." << endl;
        cout << "I should buy some at the store." << endl;
    } else if (foodCount <= 3) {
        cout << "I should buy more food soon." << endl;
    } else if (foodCount <= 6) {
        cout << "Should be enough for now." << endl;
    } else {
        cout << "Plenty. I don't think I need to buy more." << endl;
    }
}

void play(PARAMS) {
    char choice;
    bool validChoice = true;
    int id;

    while (true) {
        cout << "What will " << name << " play with today?" << endl;
        cout << "> [B]ack..." << endl;
        for (int i = 0; i < TOY_COUNT; i++) {
            if (toysOwned[i]) {
                cout << "> " << TOY_PROMPTS[i] << endl;
            }
        }
        cout << "> ";
        cin >> choice;
        choice = tolower(choice);
        cout << endl;

        switch (choice) {
        case 'b':
            return;
            break;

        case 'h':
            id = Hand;
            break;

        case 'x':
            id = Box;
            break;

        case 'r':
            id = Ball;
            break;

        case 'k':
            id = Skate;
            break;

        case 'd':
            id = Drone;
            break;

        default:
            validChoice = false;
            break;
        }
        if (!toysOwned[id]) {
            validChoice = false;
        }
        if (!validChoice) {
            cout << "[Invalid option]" << endl;
            pause();
            continue;
        }
        playWith(ARGS, id);
        passTime(day, hour, 1);
        pause();
        break;
    }
}

void playWith(PARAMS, int id) {
    int energyCost = TOY_ENERGY_COSTS[id];
    if (energyCost > energy) {
        cout << "Hey, " << name << "... you wanna play?" << endl;
        cout << "..." << endl;
        cout << "Hm. Looks like " << name << " is too tired for that." << endl;
        pause();
    }

    switch (id) {
    case Hand:
        cout << "Come on, " << name << "... you know you want to climb up on my hand!" << endl;
        prompt('L', "ift " + name + " up!");
        cout << "Uppies!" << endl;
        break;

    case Box:
        cout << "It's time to sit in the fort!" << endl;
        cout << name << " gets the smaller box, I get the bigger one. Hehe." << endl;
        pause();
        break;

    case Ball:
        cout << name << " seems to be running across the whole house with that ball..." << endl;
        pause();
        break;

    case Skate:
        cout << "Aww, look at " << name << " go!" << endl;
        pause();
        break;

    case Drone:
        cout << "Alright. Strap on, " << name << "..." << endl;
        prompt('S', "eatbelts locked!");
        prompt('3', "!");
        prompt('2', "!");
        prompt('1', "!");
        prompt('G', "O!");
        cout << "NYOOOOOOOOOOOOOOOOOM!" << endl;
        pause();
        ending = Joyride;
        break;

    default:
        error();
        return;
    }
    statChange("Happiness", happiness, TOY_HAPPINESS_VALUES[id], MAX_STAT);
    statChange("Energy", energy, -energyCost, MAX_STAT);
}

void feed(PARAMS) {
    char choice;
    bool validChoice = true;
    int id;
    int energyValue, happinessValue, nutritionValue;

    cout << "What should we feed " << name << "?" << endl;
    cout << "> [B]ack..." << endl;
    for (int i = 0; i < 5; i++) {
        if (foodsOwned[i] > 0) {
            cout << "> " << FOOD_PROMPTS[i] << " (" << foodsOwned[i] << " left)" << endl;
        }
    }
    cout << "> ";
    cin >> choice;
    choice = tolower(choice);
    cout << endl;

    switch (choice) {
    case 'b':
        return;
        break;

    case 'l':
        id = Leftover;
        if (
            happiness > PLAY_FOOD_HAPPINESS_MIN &&
            nutrition > PLAY_FOOD_NUTRITION_MAX &&
            energy > PLAY_FOOD_ENERGY_MIN
        ) {
            cout << "Hmm. " << name << " doesn't seem to like the food." << endl;
            pause();
            cout << "Wait... what is it doing with the food?" << endl;
            cout << name << " is playing with it?" << endl;
            prompt('O', "kay?");
            statChange("Happiness", happiness, TOY_HAPPINESS_VALUES[Food], MAX_STAT);
            statChange("Energy", energy, -TOY_HAPPINESS_VALUES[Food], MAX_STAT);
            passTime(day, hour, 1);
            pause();
            return;
        }
        break;

    case 'f':
        id = Fish;
        break;

    case 'p':
        id = PetFood;
        break;

    case 'c':
        id = Chicken;
        break;

    case 's':
        id = Steak;
        break;

    default:
        validChoice = false;
        break;
    }
    if (foodsOwned[id] <= 0) {
        validChoice = false;
    }
    if (!validChoice) {
        cout << "[Invalid option]" << endl;
        pause();
        return;
    }

    feedWith(ARGS, id);
    statChange(FOOD_COUNT_NAMES[id], foodsOwned[id], -1, UNLIMITED);
    passTime(day, hour, 1);
}

void feedWith(PARAMS, int id) {
    bool onlyLeftover = true;
    for (int i = 0; i < FOOD_COUNT; i++) {
       if (foodsOwned[i] > 0) {
           onlyLeftover = false;
           break;
       }
    }
    switch (id) {
    case Leftover:
        cout << "Sorry, " << name << "... but this is all ";
        if (onlyLeftover) {
            cout << "we have." << endl;
        } else {
            cout << "you'll get for now." << endl;
        }
        prompt('F', "eed");
        break;

    case Fish:
        cout << "Have a fish." << endl;
        cout << "Good thing these are boneless." << endl;
        prompt('F', "eed");
        break;

    case PetFood:
        cout << "Psst... " << name << "..." << endl;
        prompt('C', "atch!");
        break;

    case Chicken:
        cout << "I used to love these as a kid." << endl;
        cout << "Well... I still do." << endl;
        prompt('F', "eed");
        break;

    case Steak:
        cout << "Mom wouldn't want me to feed you something this expensive..." << endl;
        cout << "But have at it, " << name << "!" << endl;
        prompt('F', "eed...");
        break;

    default:
        error();
        return;
    }
    statChange("Energy", energy, FOOD_ENERGY_VALUES[id], MAX_STAT);
    statChange("Nutrition", nutrition, FOOD_NUTRITION_VALUES[id], MAX_STAT + MAX_NUTRITION_OVERFLOW);
    statChange("Happiness", happiness, FOOD_HAPPINESS_VALUES[id], MAX_STAT);
    if (nutrition > MAX_STAT) {
        cout << name << " ate too much..." << endl;
        statChange("Health", health, MAX_STAT - nutrition, MAX_STAT);
        prompt('O', "ops...");
    } else {
        pause();
    }
}

// if cap is positive, that is the maximum possible value for that stat.
// if cap is negative, will use modulo.
void statChange(string statName, int& stat, int change, int cap) {
    int oldStat = stat;
    stat += change;

    if (cap > 0) {
        stat = min(max(0, stat), cap);
    } else if (cap < 0) {
        stat = stat % -cap;
    }

    if (stat == oldStat) {
        return;
    }

    cout << statName;
    if (change > 0) {
        cout << " + " << change;
    } else {
        cout << " - " << -change;
    }
    cout << " (Now " << stat << ")" << endl;
}

void passTime(int & day, int & hour, int amount) {
    int hourAfterChange = hour + amount;
    statChange("Hour", hour, amount, -24);
    statChange("Day", day, hourAfterChange / 24, DAY_LIMIT + 1);
}

void sleep(PARAMS) {
    const string EVAL_STRINGS[] = {
        "was", "very happy today",
        "has", "been eating well",
        "was", "tired enough when it slept",
        "did", "sleep at the right time"
    };
    const int EVAL_COUNT = 4;
    bool sleptWell = HEALTHY_BEDTIME_MIN <= hour && hour <= HEALTHY_BEDTIME_MAX;
    int healthChange;
    int happinessCost = SLEEP_HAPPINESS_COST;
    int nutritionCost = SLEEP_NUTRITION_COST;
    int energyBonus = SLEEP_ENERGY_BONUS;
    bool evalConditions[] = {
        happiness >= HEALTHY_HAPPINESS_MIN,
        nutrition >= HEALTHY_NUTRITION_MIN,
        energy <= HEALTHY_ENERGY_MAX,
        sleptWell
    };
    int wakeTime = TIME_WAKE;

    cout << "Sleepy time..." << endl;
    prompt('G', "ood night...");

    cout << name << "'s health changes as it sleeps..." << endl;
    pause();
    for (int i = 0; i < EVAL_COUNT; i++) {
        healthChange = HEALTH_BONUS;
        cout << "Your pet " << EVAL_STRINGS[i * 2] << " ";
        if (!evalConditions[i]) {
            cout << "not ";
            healthChange *= -1;
        }
        cout << EVAL_STRINGS[i * 2 + 1] << "." << endl;
        statChange("Health", health, healthChange, MAX_STAT);
    }

    if (!sleptWell) {
        energyBonus /= 2;
        happinessCost *= 2;
    }
    statChange(
        "Energy",
        energy,
        energyBonus + day,
        MAX_STAT
    );
    statChange(
        "Nutrition",
        nutrition,
        -nutritionCost - day,
        MAX_STAT
    );
    statChange(
        "Happiness",
        happiness,
        -happinessCost - day,
        MAX_STAT
    );
    pause();

    if (health <= 0) {
        ending = Sick;
    } else if (nutrition <= 0) {
        ending = Hungry;
    } else if (happiness <= 0) {
        ending = Unhappy;
    } else if (day > DAY_LIMIT) {
        ending = NewYear;
        wakeTime = MIDNIGHT;
    }
    passTime(day, hour, (wakeTime + 24 - hour) % 24);

    if (sleptWell) {
        cout << "Ah, a good night's sleep." << endl;
        prompt('G', "ood morning.");
    } else {
        cout << "Ughh. I feel groggy. I don't want to wake up." << endl;
        cout << "Can I sleep for 5 more minutes ? " << endl;
        prompt('N', "o. Wake up.");
    }

    if (ending != Ongoing) {
        return;
    }

    cout << name << " is still sleeping. I'll get ready for work." << endl;
    prompt('W', "ork");
    passTime(day, hour, CLOCK_OUT - hour);
    cout << "Most of the money goes to keeping the house running, as usual..." << endl;
    cout << "...and " << INCOME << " goes for my pet's budget." << endl;
    statChange("Pet Budget", money, INCOME, UNLIMITED);
    statChange("Leftovers", foodsOwned[Leftover], 1, 1);
    if (petScore(ARGS) >= GREETING_SCORE_MIN) {
        cout << "I should probably che- huh?" << endl;
        prompt('C', "atch pet");
        cout << name << " jumps into your hands." << endl;
        cout << "Hey! I'm back from work now." << endl;
        cout << "As I was saying..." << endl;
    }
    cout << "I should probably check a couple things before doing anything." << endl;
    pause();
}

void visitStore(PARAMS) {
    char choice;
    bool validChoice;
    bool toy;
    int id;
    int price;
    int itemsBought = 0;

    if (hour > STORE_CLOSING) {
        cout << "Store's closed by now. I'll have to visit tomorrow." << endl;
        pause();
        return;
    }

    while (true) {
        validChoice = true;

        cout << "* Welcome to FurFriends! How may I help you today?" << endl;
        cout << "Pet budget: PHP " << money << endl;
        cout << endl;
        cout << "> [L]eave" << endl;

        for (int i = 1; i < TOY_COUNT; i++) {
            if (!toysOwned[i]) {
                cout << "> Buy " << TOY_PROMPTS[i] << " (PHP " << TOY_PRICES[i] << ")" << endl;
            }
        }

        for (int i = 1; i < FOOD_COUNT; i++) {
            cout << "> Buy " << FOOD_PROMPTS[i] << " (PHP " << FOOD_PRICES[i] << ")" << endl;
        }

        cout << "> ";
        cin >> choice;
        choice = tolower(choice);
        cout << endl;

        switch (choice) {
        case 'l':
            cout << "* Thank you for shopping at FurFriends. Come again next time!" << endl;
            if (itemsBought == 0) {
                cout << "* (these window shoppers...)" << endl;
            } else if (itemsBought >= MANY_ITEMS_BOUGHT) {
                cout << "* (this guy must be rich or something...)" << endl;
            }
            prompt('G', "oodbye");
            passTime(day, hour, 1);
            return;
            break;

        case 'x':
            toy = true;
            id = Box;
            break;

        case 'r':
            toy = true;
            id = Ball;
            break;

        case 'k':
            toy = true;
            id = Skate;
            break;

        case 'd':
            toy = true;
            id = Drone;
            break;

        case 'f':
            toy = false;
            id = Fish;
            break;

        case 'p':
            toy = false;
            id = PetFood;
            break;

        case 'c':
            toy = false;
            id = Chicken;
            break;

        case 's':
            toy = false;
            id = Steak;
            break;

        default:
            validChoice = false;
            break;
        }

        if (toy) {
            price = TOY_PRICES[id];
            if (toysOwned[id]) {
                validChoice = false;
            }
        } else {
            price = FOOD_PRICES[id];
        }
        if (!validChoice) {
            cout << "[Invalid option, try again]" << endl;
            pause();
            continue;
        }
        if (money < price) {
            cout << "That's outside my budget..." << endl;
            pause();
            continue;
        }

        if (toy) {
            toysOwned[id] = true;
        } else {
            foodsOwned[id]++;
        }
        statChange("Pet Budget", money, -price, UNLIMITED);
        itemsBought++;
        cout << "'Thank you for your purchase!'" << endl;
        prompt('T', "hank you too");
    }

    passTime(day, hour, 1);
}

void quit(PARAMS) {
    cout << "(You can just press Ctrl+C to force quit anytime)" << endl;
    if (!confirm("Are you sure you wanna give up?")) {
        cout << "I knew it. Who could say no to that little face." << endl;
        pause();
        return;
    }
    if (!confirm("Will you give " + name + " to your neighbor, Kate, instead?")) {
        cout << "Then you'll have to stay." << endl;
        pause();
        return;
    }
    cout << "Alright then. We'll call her up today, and say goodbye to " << name << " tomorrow." << endl;
    ending = GiveUp;
    pause();
    sleep(ARGS);
}

void playEnding(PARAMS) {
    switch (ending) {
    case Ongoing:
        return;

    case GiveUp:
        cout << "You donated your pet to your neighbor Kate." << endl;
        prompt('Y', "eah...");
        cout << "She'll take good care of " << name << ". It's a promise." << endl;
        pause();
        cout << "Rest easy. You still have stuff to do later." << endl;
        pause();
        break;

    case Joyride:
        cout << "Uh... " << name << " just..." << endl;
        prompt('W', "hat?");
        cout << name << " just took off with the drone." << endl;
        prompt('H', "ow?");
        cout << "I don't know! He just- stole the controller and-" << endl;
        cout << name << "is just gone now!" << endl;
        prompt('O', "k?");
        cout << "Wherever it's going, it's probably home." << endl;
        pause();
        break;

    case Unhappy:
        cout << "Uh... " << name << " is gone." << endl;
        prompt('W', "hat?");
        cout << "I... I don't know. Let's look around." << endl;
        pause();
        cout << "You looked around for " << name << ", and found your pet with your neighbor Kate." << endl;
        pause();
        cout << "It looks... happy." << endl;
        cout << "Happier than when you took care of it." << endl;
        prompt('Y', "eah...");
        break;

    case Hungry:
        cout << "Uh, is that..." << endl;
        prompt('W', "hat?");
        cout << "That's " << name << "!" << endl;
        pause();
        cout << "It's stealing my breakfast!" << endl;
        prompt('G', "o after it!");
        cout << "No! It ran straight through the door!" << endl;
        cout << "Drats. It's gone." << endl;
        cout << "Well, it's not hungry anymore, is it?" << endl;
        prompt('T', "rue.");
        break;

    case Sick:
        cout << "Uh, is that..." << endl;
        prompt('W', "hat?");
        cout << "That's not good." << endl;
        cout << name << " looks... really, really sick." << endl;
        prompt('V', "eterinarian?");
        cout << "Yeah, this isn't good anymore. Let's take " << name << " to a vet." << endl;
        pause();
        cout << "Apparently... I can't take care of " << name << " anymore." << endl;
        cout << "I guess... I'll just leave it here. With the shelter." << endl;
        cout << "..." << endl;
        prompt('A', "ww...");
        cout << "Looks like " << name << " is having fun with the cats." << endl;
        break;

    case NewYear:
        cout << "..." << endl;
        prompt('Z', "zz...");
        cout << "...rr..." << endl;
        prompt('Z', "zz...");
        cout << "prrr... prrr..." << endl;
        prompt('H', "uh?");
        cout << "Wh-" << endl;
        cout << "*WHISTLEEEE*" << endl;
        cout << "*BANG*" << endl;
        cout << "Now playing: Wintergatan - Starmachine2000 (for extra immersion)" << endl;
        statChange("Happiness", happiness, MAX_STAT, MAX_STAT * 2);
        prompt('C', "heck calendar");
        cout << "Let's look at how we're doing..." << endl;
        cout << "Date: January 1, 2000" << endl;
        prompt('C', "heck clock");
        cout << "Let's look at how we're doing..." << endl;
        showTime(hour);
        prompt('C', "heck pet");
        checkPet(ARGS);
        cout << "WOW!" << endl;
        prompt('G', "o outside");
        cout << "*WHISTLE NYOOM SSSS-BOOM!* *c-r-a-c-k-l-e*" << endl;
        cout << name << " jumps on your hand.";
        prompt('L', "ift " + name + " up!");
        cout << "Uppies!" << endl;
        statChange("Happiness", happiness, TOY_HAPPINESS_VALUES[Hand], MAX_STAT * 2);
        prompt('C', "all your neighbor Kate");
        cout << "HEY! KATE! COME CHECK OUT THE FIREWORKS!" << endl;
        cout << "* You mean the fireworks that _I_ launched?" << endl;
        cout << "Those were yours?! They're amazing!" << endl;
        cout << "* Yeah, I know." << endl;
        cout << "* Hey animal thing, catch!" << endl;
        feedWith(ARGS, Steak);
        cout << "This is the best day ever, isn't it, " << name << "?" << endl;
        cout << "* PUFF!" << endl;
        prompt('T', "he end.");
        break;

    default:
        error();
        return;
    }

    if (ending != NewYear) {
        cout << "*Sigh.* At least it's happy now." << endl;
        prompt('G', "oodbye...");
    }
}

void error() {
    cout << "AN ERROR OCCURRED RIP" << endl;
    pause();
}
