#include <iostream>
#include <string>
using namespace std;

// sir please let us use classes and headers grrr i want more code organization

// TODO:
// implement feeding
// test stuff
// replace these params before passing

const int INCOME = 500;
const int LOW_MONEY = 50;
const int TIME_LATE_NIGHT = 12 + 8;
const int STORE_CLOSING = 12 + 7;
const int CLOCK_OUT = 10;

const int PRICE_BOX = 25;
const int PRICE_BALL = 50;
const int PRICE_SKATE = 500;
const int PRICE_DRONE = 2000;
const int PRICE_FISH = 20;
const int PRICE_PET = 30;
const int PRICE_CHICKEN = 40;
const int PRICE_BEEF = 60;

// gameplay constants

const int MAX_STAT = 100;
const int NUTRITION_THRESHOLD = 50;
const int HAPPINESS_THRESHOLD = 50;
const int ENERGY_THRESHOLD = 50;
const int SLEEP_TIME_MIN = 12 + 6;
const int SLEEP_TIME_MAX = 12 + 10;
const int HEALTH_BONUS = 5;
const int SLEEP_ENERGY_BONUS = 50;
const int SLEEP_NUTRITION_COST = 20;

const int PLAY_FOOD_ENERGY = 50;
const int PLAY_FOOD_HAPPINESS = 50;

const int FOOD_LEFTOVER_ID = 0;
const int FOOD_FISH_ID = 1;
const int FOOD_PET_ID = 2;
const int FOOD_CHICKEN_ID = 3;
const int FOOD_BEEF_ID = 4;

const int FOOD_ENERGY[] = {5, 10, 15, 20, 25};
const int FOOD_NUTRITION[] = {5, 10, 15, 20, 25};
const int FOOD_HAPPINESS[] = {5, 10, 15, 20, 25};

const string MONTH = "December";
const int YEAR = 1999;

#define PARAMS                 \
    bool &toyBoxOwned,         \
        bool &toyBallOwned,    \
        bool &toySkateOwned,   \
        bool &toyDroneOwned,   \
        int &foodFishCount,    \
        int &foodPetCount,     \
        int &foodChickenCount, \
        int &foodBeefCount,    \
        int &happiness,        \
        int &nutrition,        \
        int &energy,           \
        int &health,           \
        string &name,          \
        int &money,            \
        int &day,              \
        int &hour,             \
        int &end

#define ARGS              \
    toyBoxOwned,          \
        toyBallOwned,     \
        toySkateOwned,    \
        toyDroneOwned,    \
        foodFishCount,    \
        foodPetCount,     \
        foodChickenCount, \
        foodBeefCount,    \
        happiness,        \
        nutrition,        \
        energy,           \
        health,           \
        name,             \
        money,            \
        day,              \
        hour,             \
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

void passTime(int &day, int &hour);
void sleep(PARAMS);
void statChange(string statName, int &stat, int change, int cap);
void statCheck(string statName, int &stat, bool cond, int value, int cap);
void visitStore(PARAMS);

void quit(PARAMS);

void ending(PARAMS);
void error();

int main()
{
    // toys owned
    bool toyBallOwned = false;
    bool toyBoxOwned = false;
    bool toySkateOwned = false;
    bool toyDroneOwned = false;

    // food owned
    int foodFishCount = 2;
    int foodPetCount = 0;
    int foodChickenCount = 1;
    int foodBeefCount = 0;

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
    switch (score)
    {
    case 9:
        cout << "I just wanna squish" << name << "..." << endl;
        break;
    case 8:
        cout << "Aww, " << name << "is so cute." << endl;
        break;
    case 7:
        cout << "Who is it? It's " << name << "!" << endl;
        break;
    case 6:
        cout << "Looks like " << name << " is looking good!" << endl;
        break;
    case 5:
        cout << "Say hi to" << name << " again!" << endl;
        break;
    case 4:
        cout << "Take care of " << name << "!" << endl;
        break;
    case 3:
        cout << "Hm, " << name << " doesn't look too good." << endl;
        break;
    case 2:
        cout << "Hey, looks like " << name << " needs a little care." << endl;
        break;
    case 1:
        cout << "Uh, " << name << " looks a bit sick." << endl;
        break;
    case 0:
        cout << "Listen. " << name << " deserves better." << endl;
        break;
    }
}

void menu(PARAMS)
{
    char choice;

    remarkAboutPet(ARGS);

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
    cout << "> Let " << name << " [S]leep" << endl;
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
            pause();
            break;
        }
        pause();
    }
}

void checkPet(PARAMS)
{
    cout << "Alright, let's see how " << name << " is doing..." << endl;
    cout << "Name: " << name << endl;
    cout << "Happiness: " << happiness << endl;
    cout << "Nutrition: " << nutrition << endl;
    cout << "Energy: " << energy << endl;
    cout << "Health: " << health << endl;
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

    if (toyBoxOwned)
    {
        cout << "We have some cardboard boxes..." << endl;
        toyCount++;
    }
    if (toyBallOwned)
    {
        cout << "There's a rubber ball..." << endl;
        toyCount++;
    }
    if (toySkateOwned)
    {
        cout << "There's a cool skateboard..." << endl;
        toyCount++;
    }
    if (toyDroneOwned)
    {
        cout << "That's a super cool drone..." << endl;
        toyCount++;
    }

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

    if (foodFishCount > 0)
    {
        cout << "We have " << foodFishCount << " piece";
        if (foodFishCount != 1)
        {
            cout << "s";
        }
        cout << " of fish..." << endl;
        foodCount += foodFishCount;
    }
    if (foodPetCount > 0)
    {
        cout << "We have " << foodPetCount << " serving";
        if (foodPetCount != 1)
        {
            cout << "s";
        }
        cout << " of pet food..." << endl;
        foodCount += foodPetCount;
    }
    if (foodChickenCount > 0)
    {
        cout << "We have " << foodChickenCount << " chicken nugget";
        if (foodChickenCount != 1)
        {
            cout << "s";
        }
        cout << "..." << endl;
        foodCount += foodChickenCount;
    }
    if (foodBeefCount > 0)
    {
        cout << "We have " << foodBeefCount << " slice";
        if (foodBeefCount != 1)
        {
            cout << "s";
        }
        cout << " of beef..." << endl;
        foodCount += foodBeefCount;
    }

    if (foodCount == 0)
    {
        cout << "..." << endl;
        cout << "That's not good." << endl;
        cout << "There's nothing." << endl;
        cout << "I should buy some at the store." << endl;
    }
    else if (foodCount < 2)
    {
        cout << "I should buy more food soon." << endl;
    }
    else if (foodCount < 7)
    {
        cout << "Should be enough for now." << endl;
    }
    else
    {
        cout << "Plenty. I don't think I need to buy more unless " << name << " doesn't like what we have." << endl;
    }
}

void play(PARAMS)
{
    char choice;
    bool validChoice = true;
    int energyCost, happinessValue;

    cout << "What will " << name << " play with today?" << endl;

    cout << "> [B]ack..." << endl;
    cout << "> my [H]and" << endl;

    if (toyBoxOwned)
    {
        cout << "> cardboard bo[X]es" << endl;
    }
    if (toyBallOwned)
    {
        cout << "> [R]ubber ball" << endl;
    }
    if (toySkateOwned)
    {
        cout << "> cool [S]kateboard" << endl;
    }
    if (toyDroneOwned)
    {
        cout << "> super cool [D]rone" << endl;
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
        energyCost = 5;
        happinessValue = 5;
        cout << "Come on, " << name << "... you know you want to climb up on my hand!" << endl;
        prompt('L', "ift " + name + " up!");
        cout << "Uppies!" << endl;
        break;

    case 'x':
        if (!toyBoxOwned)
        {
            validChoice = false;
            break;
        }
        energyCost = 5;
        happinessValue = 5;
        cout << "It's time to sit in the fort!" << endl;
        cout << name << " gets the smaller box, I get the bigger one. Hehe." << endl;
        pause();
        break;

    case 'r':
        if (!toyBallOwned)
        {
            validChoice = false;
            break;
        }
        energyCost = 10;
        happinessValue = 10;
        cout << name << " seems to be running across the whole house with that ball..." << endl;
        pause();
        break;

    case 's':
        if (!toySkateOwned)
        {
            validChoice = false;
            break;
        }
        energyCost = 15;
        happinessValue = 15;
        cout << "Aww, look at " << name << " go!" << endl;
        pause();
        break;
    case 'd':
        if (!toyDroneOwned)
        {
            validChoice = false;
            break;
        }
        energyCost = 20;
        happinessValue = 20;
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
    statChange("Happiness", happiness, happinessValue, MAX_STAT);
    statChange("Energy", energy, -energyCost, MAX_STAT);
    passTime(day, hour);
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
    cout << "> some [L]eftovers from last meal (Always available)" << endl;
    if (foodFishCount > 0)
    {
        cout << "> a piece of [F]ish (" << foodFishCount << " left)" << endl;
    }
    if (foodPetCount > 0)
    {
        cout << "> a serving of [P]et food (" << foodPetCount << " left)" << endl;
    }
    if (foodChickenCount > 0)
    {
        cout << "> a [C]hicken nugget (" << foodChickenCount << " left)" << endl;
    }
    if (foodBeefCount > 0)
    {
        cout << "> a slice of [B]eef (" << foodBeefCount << " left)" << endl;
    }

    cout << "> ";
    cin >> choice;
    choice = tolower(choice);
    cout << endl;

    switch (choice)
    {
    case 'l':
        if (energy > PLAY_FOOD_ENERGY && happiness > PLAY_FOOD_HAPPINESS)
        {
            cout << "Hmm. " << name << " doesn't seem to like the food." << endl;
            pause();
            cout << "Wait... what is it doing with the food?" << endl;
            cout << name << " is playing with it?" << endl;
            prompt('O', "kay?");

            statChange("Happiness", happiness, 10, MAX_STAT);
            statChange("Energy", energy, -10, MAX_STAT);
            return;
        }
        id = 0;
        break;
    case 'f':
        if (foodFishCount <= 0)
        {
            validChoice = false;
            break;
        }
        statChange("Fish Count", foodFishCount, -1, -1);
        id = 1;
        break;
    case 'p':
        if (foodPetCount <= 0)
        {
            validChoice = false;
            break;
        }
        statChange("Pet food Count", foodPetCount, -1, -1);
        id = 2;
        break;
    case 'c':
        if (foodChickenCount <= 0)
        {
            validChoice = false;
            break;
        }
            statChange("Chickend CounuggetoodPetCountChicken1);
            id = 2;
        break;
        default:
            validChoice = false;
        break;
    }

    // TODO: increase nutrition and energy
    // happiness increases or decreases depending on food chosen
    // select food item depending on money
    // if energy is too high and the pet doesnt like the food, pet will play with food instead, calling play();
    // if energy too low, the pet will refuse to eat
    // if nutrition exceeds a threshold, decrease health
    passTime(day, hour);
}

void statChange(string statName, int &stat, int change, int cap)
{
    if (change == 0)
    {
        return;
    }

    if (change > 0)
    {
        cout << statName << " + " << change << endl;
    }
    else
    {
        cout << statName << " - " << -change << endl;
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
}

void statCheck(string statName, int &stat, string meaning, bool cond, int value, int cap)
{
    cout << "Your pet has ";
    if (cond)
    {
    }
    else
    {
        value *= -1;
        cout << "not ";
    }
    cout << meaning << "." << endl;
    statChange(statName, stat, value, cap);
}

void passTime(int &day, int &hour)
{
    statChange("Hour", hour, 1, 24);
    if (hour >= 24)
    {
        cout << "It's past midnight." << endl;
        cout << "I should sleep." << endl;
        pause();
    }
}

void sleep(PARAMS)
{
    bool sleptWell = hour >= SLEEP_TIME_MIN && hour <= SLEEP_TIME_MAX;

    cout << "Sleepy time..." << endl;
    prompt('G', "ood night...");

    cout << name << "'s health changes as it sleeps..." << endl;
    pause();
    statCheck(
        "Health",
        health,
        "been eating well",
        nutrition > NUTRITION_THRESHOLD,
        HEALTH_BONUS,
        MAX_STAT);
    statCheck(
        "Health",
        health,
        "been very happy",
        happiness > HAPPINESS_THRESHOLD,
        HEALTH_BONUS,
        MAX_STAT);
    statCheck(
        "Health",
        health,
        "been very active today",
        energy < ENERGY_THRESHOLD,
        HEALTH_BONUS,
        MAX_STAT);
    statCheck(
        "Health",
        health,
        "slept at the right time",
        sleptWell,
        HEALTH_BONUS,
        MAX_STAT);
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

    statChange("Day", day, 1, -1);
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
    hour = 5;

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

    if (end != 0)
    {
        return;
    }

    cout << name << " is still sleeping. I'll go to work." << endl;
    prompt('W', "ork");
    statChange("Hour", hour, CLOCK_OUT, 24);
    cout << "Most of the money goes to keeping the house running, as usual..." << endl;
    cout << "...and " << INCOME << " goes for my pet's budget." << endl;
    statChange("Pet Budget", money, 500, -1);
    pause();
}

void visitStore(PARAMS)
{
    char choice;
    int err;
    int itemsBought = 0;

    if (hour > STORE_CLOSING)
    {
        cout << "Store's closed by now. I'll have to visit tomorrow." << endl;
        pause();
        return;
    }

    while (true)
    {
        err = 0;

        // L, XRSD, FPCB
        cout << "'Welcome to FurFriends, how may I help you today?'" << endl;
        cout << endl;
        cout << "Pet budget: PHP " << money << endl;
        cout << endl;
        cout << "> [L]eave" << endl;

        if (!toyBoxOwned)
        {
            cout << "> Buy cardboard bo[X]es (PHP " << PRICE_BOX << ")" << endl;
        }
        if (!toyBallOwned)
        {
            cout << "> Buy [R]ubber ball (PHP " << PRICE_BALL << ")" << endl;
        }
        if (!toySkateOwned)
        {
            cout << "> Buy cool [S]kateboard (PHP " << PRICE_SKATE << ")" << endl;
        }
        if (!toyDroneOwned)
        {
            cout << "> Buy super cool [D]rone (PHP " << PRICE_DRONE << ")" << endl;
        }

        cout << "> Buy a piece of [F]ish (PHP " << PRICE_FISH << ")" << endl;
        cout << "> Buy a serving of [P]et food (PHP " << PRICE_PET << ")" << endl;
        cout << "> Buy a [C]hicken nugget (PHP " << PRICE_CHICKEN << ")" << endl;
        cout << "> Buy a slice of [B]eef (PHP " << PRICE_BEEF << ")" << endl;

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
            return;
            break;

        case 'x':
            if (toyBoxOwned)
            {
                err = 1;
                break;
            }
            if (money < PRICE_BOX)
            {
                err = 2;
                break;
            }
            toyBoxOwned = true;
            break;
        case 'r':
            if (toyBallOwned)
            {
                err = 1;
                break;
            }
            if (money < PRICE_BALL)
            {
                err = 2;
                break;
            }
            toyBallOwned = true;
            break;
        case 's':
            if (toySkateOwned)
            {
                err = 1;
                break;
            }
            if (money < PRICE_SKATE)
            {
                err = 2;
                break;
            }
            toySkateOwned = true;
            break;
        case 'd':
            if (toyDroneOwned)
            {
                err = 1;
                break;
            }
            if (money < PRICE_DRONE)
            {
                err = 2;
                break;
            }
            toyDroneOwned = true;
            break;

        case 'f':
            if (money < PRICE_FISH)
            {
                err = 2;
                break;
            }
            foodFishCount++;
            break;
        case 'p':
            if (money < PRICE_PET)
            {
                err = 2;
                break;
            }
            foodPetCount++;
            break;
        case 'c':
            if (money < PRICE_CHICKEN)
            {
                err = 2;
                break;
            }
            foodChickenCount++;
            break;
        case 'b':
            if (money < PRICE_BEEF)
            {
                err = 2;
                break;
            }
            foodBeefCount++;
            break;

        default:
            err = 1;
            break;
        }
        switch (err)
        {
        case 0:
            itemsBought++;
            cout << "Thank you for your purchase!" << endl;
            prompt('T', "hank you too");
            break;
        case 1:
            cout << "[Invalid option]" << endl;
            pause();
            break;
        case 2:
            cout << "That's outside my budget..." << endl;
            pause();
            break;
        }
    }

    passTime(day, hour);
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
// if rest or energy goes to 0, pet sleeps and you are forced into sleep()
void ending(PARAMS)
{
    if (end == 0)
    {
        return;
    }

    switch (end)
    {
    // should've been caught earlier
    case 0:
        error();
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
