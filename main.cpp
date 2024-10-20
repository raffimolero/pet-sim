#include <iostream>
#include <string>
using namespace std;

// sir please let us use classes and headers grrr i want more code organization

// TODO:
// implement new year ending
// test stuff
// fix "thank you for your purchase" when outside budget
// replace these params before passing

#define PARAMS            \
    bool toysOwned[],     \
        int foodsOwned[], \
        int &happiness,   \
        int &nutrition,   \
        int &energy,      \
        int &health,      \
        string &name,     \
        int &money,       \
        int &day,         \
        int &hour,        \
        int &end

#define ARGS        \
    toysOwned,      \
        foodsOwned, \
        happiness,  \
        nutrition,  \
        energy,     \
        health,     \
        name,       \
        money,      \
        day,        \
        hour,       \
        end

bool confirm(string text);
void prompt(char expected, string text);
void pause();

void findPet(PARAMS);
void namePet(PARAMS);
void menu(PARAMS);

void remarkAboutPet(PARAMS);

void check(PARAMS);
void checkPet(PARAMS);
void checkCalendar(PARAMS);
void showTime(int hour);
void checkToys(PARAMS);
void checkFood(PARAMS);

void play(PARAMS);
void feed(PARAMS);

void passTime(int &day, int &hour, int amount);
void sleep(PARAMS);
void statCheck(string statName, int stat);
void statChange(string statName, int &stat, int change, int cap);
void visitStore(PARAMS);

void quit(PARAMS);

void ending(PARAMS);
void error();

// gameplay constants
const int INCOME = 500;
const int LOW_MONEY = 50;
const int TIME_WAKE = 6;
const int TIME_LATE_NIGHT = 12 + 8;
const int STORE_CLOSING = 12 + 7;
const int CLOCK_OUT = 12 + 6;

// pet related stats
const int MAX_STAT = 100;
const int NUTRITION_THRESHOLD = 50;
const int HAPPINESS_THRESHOLD = 50;
const int ENERGY_THRESHOLD = 50;
const int SLEEP_TIME_MIN = 12 + 6;
const int SLEEP_TIME_MAX = 12 + 10;
const int HEALTH_BONUS = 5;
const int SLEEP_ENERGY_BONUS = 50;
const int SLEEP_NUTRITION_COST = 20;

// toy data
enum Toy
{
    Hand,
    Box,
    Ball,
    Skate,
    Drone,
    Food,
};

const string TOY_PROMPTS[] = {
    "my [H]and",
    "cardboard bo[X]es",
    "[R]ubber ball",
    "cool s[K]ateboard",
    "super cool [D]rone"};
const int TOY_PRICES[] = {0, 25, 50, 500, 2000};
const int TOY_ENERGY_COSTS[] = {5, 5, 10, 15, 25, 5};
const int TOY_HAPPINESS_VALUES[] = {5, 5, 10, 15, 25, 5};

const int PLAY_FOOD_ENERGY_THRESHOLD = 50;
const int PLAY_FOOD_HAPPINESS_THRESHOLD = 50;

// food data
const int FOOD_LEFTOVER_ID = 0;
const int FOOD_FISH_ID = 1;
const int FOOD_PET_ID = 2;
const int FOOD_CHICKEN_ID = 3;
const int FOOD_STEAK_ID = 4;

const string FOOD_PROMPTS[] = {
    "some [L]eftovers from last meal",
    "a piece of [F]ish",
    "a serving of [P]et food",
    "a [C]hicken nugget",
    "a slice of [S]teak"};
const string FOOD_COUNT_NAMES[] = {
    "Leftover",
    "Fish",
    "Pet Food",
    "Chicken",
    "Steak"};
const int FOOD_PRICES[] = {0, 20, 30, 40, 60};
const int FOOD_ENERGY_VALUES[] = {-2, 0, 2, 4, 6};
const int FOOD_NUTRITION_VALUES[] = {5, 10, 15, 20, 25};
const int FOOD_HAPPINESS_VALUES[] = {-5, 0, 5, 10, 15};

const string MONTH = "December";
const int YEAR = 1999;

int main()
{
    // hand, box, ball, skate, drone
    bool toysOwned[] = {true, false, false, false, false};
    // leftover, fish, pet food, chicken, steak
    int foodsOwned[] = {1, 2, 0, 1, 0, 0};

    // other stats
    int money = 200;
    int day = 1;
    int hour = 12 + 8;
    int end = 0;

    // pet stats
    int happiness = 30;
    int nutrition = 30;
    int energy = 30;
    int health = 30;
    string name = "[unnamed creature]";

    findPet(ARGS);

    while (end == 0)
    {
        menu(ARGS);
    }
    ending(ARGS);

    return 0;
}

bool confirm(string text)
{
    char input;
    while (true)
    {
        cout << text << endl;
        cout << "> [Y]es" << endl;
        cout << "> [N]o" << endl;
        cout << "> ";
        cin >> input;
        cout << endl;
        switch (input)
        {
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

void prompt(char expected, string text)
{
    char input;
    do
    {
        cout << "> [" << expected << "]" << text << endl;
        cout << "> ";
        cin >> input;
        cout << endl;
    } while (tolower(input) != tolower(expected));
}

void pause()
{
    prompt('O', "k");
}

void findPet(PARAMS)
{
    return;
    char choice;
    bool creatureAdopted = false;

    cout << "Nighttime." << endl;
    cout << "It's been a long week, and our coworkers left early." << endl;
    cout << "Welp, time to go home. Might as well walk." << endl;
    pause();
    cout << "Oh! What's this" << endl;
    cout << "A strange, fluffy, triangular creature..." << endl;

    while (!creatureAdopted)
    {
        cout << "What will you do with this creature?" << endl;
        cout << "> [A]dopt it" << endl;
        cout << "> [L]eave it" << endl;
        cout << "> ";
        cin >> choice;
        choice = tolower(choice);
        cout << endl;

        switch (choice)
        {
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

            happiness -= 10;
            energy -= 10;
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

void namePet(PARAMS)
{
    bool sure;
    do
    {
        name = "[unnamed]";
        cout << "What will you name your pet?" << endl;
        cout << "> ";
        cin >> name;
        cout << endl;
    } while (!confirm("Are you sure you want to call your pet " + name + "?"));
    cout << "Alright. Say hello to " << name << "!" << endl;
    prompt('H', "ello!");
}

void remarkAboutPet(PARAMS)
{
    int score = (happiness + nutrition + energy + health) / 40;
    const string REMARKS[] = {
        "Listen. ", " deserves better.",
        "Uh, ", " looks a bit sick.",
        "Hm. ", " doesn't look too good.",
        "Hey, looks like ", " needs a little care.",
        "Take care of ", "!",
        "Say hi to", " again!",
        "Looks like ", " is looking good!",
        "Who is it? It's ", "!",
        "Aww, ", " is so cute.",
        "I just wanna squish ", "..."};
    cout << REMARKS[score * 2] << name << REMARKS[score * 2 + 1] << endl;
}

void menu(PARAMS)
{
    char choice;

    remarkAboutPet(ARGS);

    // past midnight rolls over to 0
    if (hour < TIME_WAKE)
    {
        cout << "It's past midnight." << endl;
        cout << "I should sleep." << endl;
        prompt('S', "leep");
        sleep(ARGS);
        return;
    }
    if (energy <= 0)
    {
        cout << name << " is very tired now." << endl;
        prompt('S', "leep");
        sleep(ARGS);
        return;
    }

    cout << "What would you like to do?" << endl;
    cout << "> [C]heck something" << endl;
    cout << "> [R]ename " << name << " and give it another name" << endl;
    cout << "> [V]isit the Pet Store" << endl;
    cout << "> [P]lay with " << name << endl;
    cout << "> [F]eed " << name << endl;
    cout << "> [S]leep beside " << name << endl;
    cout << "> [G]ive up" << endl;
    cout << "> ";
    cin >> choice;
    choice = tolower(choice);
    cout << endl;

    switch (choice)
    {
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

void check(PARAMS)
{
    char choice;

    while (true)
    {
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

        switch (choice)
        {
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

void statCheck(string statName, int stat)
{
    cout << statName << "[";
    for (int i = 5; i < 100; i += 10)
    {
        if (stat >= i)
        {
            cout << "#";
        }
        else
        {
            cout << ".";
        }
    }
    cout << "] (" << stat << "/" << MAX_STAT << ")" << endl;
}

void checkPet(PARAMS)
{
    cout << "Alright, let's see how " << name << " is doing..." << endl;
    cout << "Name: " << name << endl;
    statCheck("Happiness: ", happiness);
    statCheck("Nutrition: ", nutrition);
    statCheck("Energy:    ", energy);
    statCheck("Health:    ", health);
}

void checkCalendar(PARAMS)
{
    cout << "Let's look at how we're doing..." << endl;

    cout << "Money: " << money << endl;
    if (money < LOW_MONEY)
    {
        cout << "Uff. Well, all of that money was saved up just for " << name << ", anyway." << endl;
        cout << "I have enough in my real savings account." << name << "." << endl;
    }
    cout << "Date: " << MONTH << " " << day << ", " << YEAR << endl;
    if (day / 7 % 4 == 3)
    {
        cout << "I almost can't believe how long it's been." << endl;
    }

    showTime(hour);
    if (hour >= TIME_LATE_NIGHT)
    {
        cout << "It's getting late. We should sleep soon." << endl;
    }
}

void showTime(int hour)
{
    bool am = hour < 12;
    int displayHour = hour;
    if (!am)
    {
        displayHour -= 12;
    }
    if (displayHour == 0)
    {
        displayHour = 12;
    }

    cout << "Time: " << displayHour;
    if (am)
    {
        cout << " A.M." << endl;
    }
    else
    {
        cout << " P.M." << endl;
    }
}

void checkToys(PARAMS)
{
    int toyCount = 0;

    cout << "Let's open the shelf." << endl;

    const string TOY_CHECK_MESSAGES[] = {
        "We have some cardboard boxes...",
        "There's a rubber ball...",
        "There's a cool skateboard...",
        "That's a super cool drone..."};

    for (int i = 0; i < 4; i++)
    {
        if (toysOwned[i])
        {
            cout << TOY_CHECK_MESSAGES[i] << endl;
            toyCount++;
        }
    }

    // shouldn't use an array of strings here since name is dynamic
    switch (toyCount)
    {
    case 0:
        cout << "There's nothing. Maybe I could buy something." << endl;
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

void checkFood(PARAMS)
{
    int foodCount = 0;

    cout << "Let's look at our food in the fridge." << endl;

    const string TEXT[] = {
        "leftover meal",
        "",
        "from lunch",

        "piece",
        "s",
        "of fish",

        "serving",
        "s",
        "of pet food",

        "chicken nugget",
        "s",
        "",

        "slice",
        "s",
        "of steak"};

    for (int i = 0; i < 5; i++)
    {
        if (foodsOwned[i] > 0)
        {
            cout << "We have " << foodsOwned[i] << " " << TEXT[i * 3];
            if (foodsOwned[i] != 1)
            {
                cout << TEXT[i * 3 + 1];
            }
            cout << " " << TEXT[i * 3 + 2] << "..." << endl;
            foodCount += foodsOwned[i];
        }
    }

    // operates over ranges, shouldn't use switch case
    if (foodCount == 1)
    {
        cout << "There's nothing good here." << endl;
        cout << "I should buy some at the store." << endl;
    }
    else if (foodCount <= 3)
    {
        cout << "I should buy more food soon." << endl;
    }
    else if (foodCount <= 6)
    {
        cout << "Should be enough for now." << endl;
    }
    else
    {
        cout << "Plenty. I don't think I need to buy more." << endl;
    }
}

void play(PARAMS)
{
    char choice;
    bool validChoice = true;
    int id;
    int energyCost, happinessValue;

    cout << "What will " << name << " play with today?" << endl;

    cout << "> [B]ack..." << endl;

    for (int i = 0; i < 5; i++)
    {
        if (toysOwned[i])
        {
            cout << "> " << TOY_PROMPTS[i] << endl;
        }
    }

    cout << "> ";
    cin >> choice;
    choice = tolower(choice);
    cout << endl;

    switch (choice)
    {
    case 'b':
        return;
        break;

    case 'h':
        id = Hand;
        cout << "Come on, " << name << "... you know you want to climb up on my hand!" << endl;
        prompt('L', "ift " + name + " up!");
        cout << "Uppies!" << endl;
        break;

    case 'x':
        id = Box;
        if (!toysOwned[id])
        {
            validChoice = false;
            break;
        }
        cout << "It's time to sit in the fort!" << endl;
        cout << name << " gets the smaller box, I get the bigger one. Hehe." << endl;
        pause();
        break;

    case 'r':
        id = Ball;
        if (!toysOwned[id])
        {
            validChoice = false;
            break;
        }
        cout << name << " seems to be running across the whole house with that ball..." << endl;
        pause();
        break;

    case 'k':
        id = Skate;
        if (!toysOwned[id])
        {
            validChoice = false;
            break;
        }
        cout << "Aww, look at " << name << " go!" << endl;
        pause();
        break;

    case 'd':
        id = Drone;
        if (!toysOwned[id])
        {
            validChoice = false;
            break;
        }
        cout << "Alright. Strap on, " << name << "..." << endl;
        prompt('S', "eatbelts locked!");
        prompt('3', "!");
        prompt('2', "!");
        prompt('1', "!");
        prompt('G', "O!");
        cout << "NYOOOOOOOOOOOOOOOOOM!" << endl;
        pause();
        end = 2;
        break;

    default:
        validChoice = false;
        break;
    }
    if (!validChoice)
    {
        cout << "[Invalid option]" << endl;
        pause();
        return;
    }

    statChange("Happiness", happiness, TOY_HAPPINESS_VALUES[id], MAX_STAT);
    statChange("Energy", energy, -TOY_ENERGY_COSTS[id], MAX_STAT);
    passTime(day, hour, 1);
    pause();
}

void feed(PARAMS)
{
    char choice;
    bool validChoice = true;
    int id;
    int energyValue, happinessValue, nutritionValue;

    cout << "What should we feed " << name << "?" << endl;

    cout << "> [B]ack..." << endl;
    for (int i = 0; i < 5; i++)
    {
        if (foodsOwned[i] > 0)
        {
            cout << "> " << FOOD_PROMPTS[i] << " (" << foodsOwned[i] << " left)" << endl;
        }
    }

    cout << "> ";
    cin >> choice;
    choice = tolower(choice);
    cout << endl;

    switch (choice)
    {
    case 'b':
        return;
        break;

    case 'l':
        id = FOOD_LEFTOVER_ID;
        if (energy > PLAY_FOOD_ENERGY_THRESHOLD && happiness > PLAY_FOOD_HAPPINESS_THRESHOLD)
        {
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
        id = FOOD_FISH_ID;
        break;

    case 'p':
        id = FOOD_PET_ID;
        break;

    case 'c':
        id = FOOD_CHICKEN_ID;
        break;

    case 's':
        id = FOOD_STEAK_ID;
        break;

    default:
        validChoice = false;
        break;
    }
    if (foodsOwned[id] <= 0)
    {
        validChoice = false;
    }
    if (!validChoice)
    {
        cout << "[Invalid option]" << endl;
        pause();
        return;
    }

    statChange(FOOD_COUNT_NAMES[id], foodsOwned[id], -1, -1);
    statChange("Energy", energy, FOOD_ENERGY_VALUES[id], MAX_STAT);
    statChange("Nutrition", nutrition, FOOD_NUTRITION_VALUES[id], MAX_STAT + 20);
    statChange("Happiness", happiness, FOOD_HAPPINESS_VALUES[id], MAX_STAT);
    if (nutrition > MAX_STAT)
    {
        cout << name << " ate too much..." << endl;
        statChange("Health", health, MAX_STAT - nutrition, MAX_STAT);
        prompt('O', "ops...");
    }
    else
    {
        pause();
    }

    passTime(day, hour, 1);
}

void statChange(string statName, int &stat, int change, int cap)
{
    if (change == 0)
    {
        return;
    }

    stat += change;

    if (cap == -1)
    {
        return;
    }
    if (stat > cap)
    {
        stat = cap;
    }
    else if (stat < 0)
    {
        stat = 0;
    }

    if (change > 0)
    {
        cout << statName << " + " << change << endl;
    }
    else
    {
        cout << statName << " - " << -change << endl;
    }
}

void passTime(int &day, int &hour, int amount)
{
    statChange("Hour", hour, amount, -1);
    if (hour >= 24)
    {
        statChange("Day", day, hour / 24, -1);
        hour %= 24;
    }
}

void sleep(PARAMS)
{
    bool sleptWell = hour >= SLEEP_TIME_MIN && hour <= SLEEP_TIME_MAX;

    cout << "Sleepy time..." << endl;
    prompt('G', "ood night...");

    cout << name << "'s health changes as it sleeps..." << endl;
    pause();
    const string EVAL_STRINGS[] = {
        "has", "been eating well",
        "was", "very happy today",
        "was", "tired enough when it slept",
        "did", "sleep at the right time"};
    bool evalConditions[] = {
        nutrition > NUTRITION_THRESHOLD,
        happiness > HAPPINESS_THRESHOLD,
        energy < ENERGY_THRESHOLD,
        sleptWell};
    for (int i = 0; i < 4; i++)
    {
        cout << "Your pet " << EVAL_STRINGS[i * 2];
        if (!evalConditions[i])
        {
            cout << "not ";
        }
        cout << EVAL_STRINGS[i * 2 + 1] << "." << endl;
        statChange("Health", health, HEALTH_BONUS, MAX_STAT);
    }

    statChange(
        "Energy",
        energy,
        SLEEP_ENERGY_BONUS - day,
        MAX_STAT);
    statChange(
        "Nutrition",
        nutrition,
        -SLEEP_NUTRITION_COST - day,
        MAX_STAT);
    pause();

    if (sleptWell)
    {
        cout << "Ah, a good night's sleep." << endl;
        prompt('G', "ood morning.");
    }
    else
    {
        cout << "Ughh. I feel groggy. I don't want to wake up." << endl;
        cout << "Can I sleep for 5 more minutes ? " << endl;
        prompt('N', "o. Wake up.");
    }
    passTime(day, hour, (TIME_WAKE + 24 - hour) % 24);

    if (happiness <= 0)
    {
        end = 3;
    }
    else if (nutrition <= 0)
    {
        end = 4;
    }
    else if (health <= 0)
    {
        end = 5;
    }
    else if (day > 31)
    {
        end = 6;
    }

    if (end != 0)
    {
        return;
    }

    cout << name << " is still sleeping. I'll go to work." << endl;
    prompt('W', "ork");
    passTime(day, hour, CLOCK_OUT - hour);
    cout << "Most of the money goes to keeping the house running, as usual..." << endl;
    cout << "...and " << INCOME << " goes for my pet's budget." << endl;
    statChange("Pet Budget", money, 500, -1);
    statChange("Leftovers", foodsOwned[FOOD_LEFTOVER_ID], 1, 1);
    cout << "I should probably check a couple things before doing anything." << endl;
    pause();
}

void visitStore(PARAMS)
{
    char choice;
    bool validChoice;
    bool toy;
    int id;
    int price;
    int itemsBought = 0;

    if (hour > STORE_CLOSING)
    {
        cout << "Store's closed by now. I'll have to visit tomorrow." << endl;
        pause();
        return;
    }

    while (true)
    {
        validChoice = true;

        // L, XRSD, FPCB
        cout << "'Welcome to FurFriends, how may I help you today?'" << endl;
        cout << endl;
        cout << "Pet budget: PHP " << money << endl;
        cout << endl;
        cout << "> [L]eave" << endl;

        for (int i = 1; i < 5; i++)
        {
            if (!toysOwned[i])
            {
                cout << "> Buy " << TOY_PROMPTS[i] << " (PHP " << TOY_PRICES[i] << ")" << endl;
            }
        }

        for (int i = 1; i < 5; i++)
        {
            cout << "> Buy " << FOOD_PROMPTS[i] << " (PHP " << FOOD_PRICES[i] << ")" << endl;
        }

        cout << "> ";
        cin >> choice;
        choice = tolower(choice);
        cout << endl;

        switch (choice)
        {
        case 'l':
            cout << "'Thanks for shopping at FurFriends, come again next time!'" << endl;
            if (itemsBought == 0)
            {
                cout << "(these window shoppers...)" << endl;
            }
            else if (itemsBought >= 4)
            {
                cout << "(this guy must be rich or something...)" << endl;
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
            id = FOOD_FISH_ID;
            break;

        case 'p':
            toy = false;
            id = FOOD_PET_ID;
            break;

        case 'c':
            toy = false;
            id = FOOD_CHICKEN_ID;
            break;

        case 's':
            toy = false;
            id = FOOD_STEAK_ID;
            break;

        default:
            validChoice = false;
            break;
        }

        if (toy)
        {
            price = TOY_PRICES[id];
            if (toysOwned[id])
            {
                validChoice = false;
            }
        }
        else
        {
            price = FOOD_PRICES[id];
        }
        if (!validChoice)
        {
            cout << "[Invalid option, try again]" << endl;
            pause();
            break;
        }
        if (money < price)
        {
            cout << "That's outside my budget..." << endl;
        }

        if (toy)
        {
            toysOwned[id] = true;
        }
        else
        {
            foodsOwned[id]++;
        }
        statChange("Pet Budget", money, -price, -1);
        itemsBought++;
        cout << "'Thank you for your purchase!'" << endl;
        prompt('T', "hank you too");
    }

    passTime(day, hour, 1);
}

void quit(PARAMS)
{
    if (confirm("Are you sure you wanna give up?"))
    {
        if (confirm("Will you give " + name + " to your neighbor, Kate, instead?"))
        {
            cout << "Alright then. We'll call her up today, and say goodbye to " << name << " tomorrow." << endl;
            end = 1;
            sleep(ARGS);
        }
        else
        {
            cout << "Then you'll have to stay." << endl;
            pause();
        }
    }
    else
    {
        cout << "I knew it. Who could say no to that little face." << endl;
        pause();
    }
}

// ENDINGS:
// 0 not over
// 1 quit, donate pet to neighbor
// 2 buy drone, the pet drives it home
// 3 happiness goes to 0, pet just leaves you and finds a different owner
// 4 nutrition goes to 0, pet steals your breakfast, leaves, and hangs out with the local cats, hisses at you
// 5 health goes to 0, you call in a vet and they take it into a shelter
// 6 new year, pet goes home to its family
void ending(PARAMS)
{
    switch (end)
    {
    // game is not over yet
    case 0:
        return;
        break;

    // quit
    case 1:
        cout << "You donated your pet to your neighbor Kate." << endl;
        prompt('Y', "eah...");
        cout << "She'll take good care of " << name << ". It's a promise." << endl;
        pause();
        cout << "Rest easy. You still have stuff to do later." << endl;
        pause();
        break;

    // play with drone
    case 2:
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

    // happiness 0
    case 3:
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

    // nutrition 0
    case 4:
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

    // health 0
    case 5:
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

    // new year
    case 6:
        // TODO:
        break;

    default:
        error();
        break;
    }
    cout << "*Sigh.* At least it's happy now." << endl;
    prompt('G', "oodbye...");
}

void error()
{
    cout << "AN ERROR OCCURRED RIP" << endl;
    pause();
}
