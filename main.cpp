#include <iostream>
#include <string>
using namespace std;

// sir please let us use classes and headers grrr i want more code organization

// TODO: replace these params before passing

const int MAX_STAT = 100;
const string MONTH = "December";

#define PARAMS \
    bool& toyBallOwned, \
    bool& toyBoxOwned, \
    bool& toySkateOwned, \
    bool& toyDroneOwned, \
    int& foodFishCount, \
    int& foodPetCount, \
    int& foodChickenCount, \
    int& foodBeefCount, \
    int& happiness, \
    int& nutrition, \
    int& energy, \
    int& rest, \
    int& health, \
    string& name, \
    int& money, \
    int& day, \
    int& hour, \
    int& end

#define ARGS \
    toyBallOwned, \
    toyBoxOwned, \
    toySkateOwned, \
    toyDroneOwned, \
    foodFishCount, \
    foodPetCount, \
    foodChickenCount, \
    foodBeefCount, \
    happiness, \
    nutrition, \
    energy, \
    rest, \
    health, \
    name, \
    money, \
    day, \
    hour, \
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
void checkToys(PARAMS);
void checkFood(PARAMS);

void play(PARAMS);

void feed(PARAMS);

void sleep(PARAMS);

void quit(PARAMS);

void ending(PARAMS);

void error();

int main() {
    // toys owned
    bool toyBallOwned = false;
    bool toyBoxOwned = false;
    bool toySkateOwned = false;
    bool toyDroneOwned = false;

    // food owned
    int foodFishCount = 0;
    int foodPetCount = 0;
    int foodChickenCount = 0;
    int foodBeefCount = 0;

    // other stats
    int money = 0;
    int day = 0;
    int hour = 0;
    int end = 0;

    // pet stats
    int happiness = 0;
    int nutrition = 0;
    int energy = 0;
    int rest = 0;
    int health = 0;
    string name = "[unnamed creature]";

    findPet(ARGS);

    while (end == 0) {
        menu(ARGS);
    }
    ending(ARGS);
  
    return 0;
}

bool confirm(string text) {
    char input;
    while (true) {
        cout << text << endl;
        cout << "> [Y]es" << endl;
        cout << "> [N]o" << endl;
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
        cout << '[' << expected << ']' << text << endl;
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

    day = 1;
    hour = 12 + 8; // 8pm
    cout << "Nighttime." << endl;
    cout << "Party's over. It's been a long week, but the project's done, and you've got a whole month off!" << endl;
    cout << "Man. This vacation is gonna be good." << endl;
    pause();
    cout << "Welp, time to go home. Might as well walk." << endl;
    pause();
    cout << "Oh! What's this" << endl;
    cout << "A strange triangular creature..." << endl;

    happiness = 30;
    nutrition = 20;
    energy = 30;
    rest = 20;
    health = 30;
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
            case 'A':
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
            case 'L':
                cout << "Well, it's time to head home." << endl;
                cout << "You walk away." << endl;
                happiness -= 10;
                energy -= 10;
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
                creatureAdopted = true;
                break;
            default:
                cout << "[Invalid option, try again]" << endl;
                cout << endl;
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
    } while (!confirm("Are you sure you want to call your pet " + name + "?"));
    cout << "Alright. Say hello to " << name << "!" << endl;
    prompt('H', "ello!");
}

void remarkAboutPet(PARAMS) {
    int score = (happiness + nutrition + energy + rest + health) / 50;
    switch (score) {
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

void menu(PARAMS) {
    char choice;

    remarkAboutPet(ARGS);
    cout << "What would you like to do?" << endl;
    cout << "> [C]heck something" << endl;
    cout << "> [R]ename " << name << " and give it another name" << endl;
    cout << "> [P]lay with " << name << endl;
    cout << "> [F]eed " << name << endl;
    cout << "> Let " << name << " [S]leep" << endl;
    cout << "> [Q]uit" << endl;
    cin >> choice;
    choice = tolower(choice);
    cout << endl;

    switch (choice) {
        case 'c':
            check(ARGS);
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
        case 'q':
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
        cin >> choice;
        choice = tolower(choice);
        cout << endl;

        switch (choice) {
            case 'b':
                return;
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
                cout << endl;
                break;
        }
        pause();
    }
}

void checkPet(PARAMS) {
    cout << "Alright, let's see how " << name << " is doing..." << endl;
    cout << "Name: " << name << endl;
    cout << "Happiness: " << happiness << endl;
    cout << "Nutrition: " << nutrition << endl;
    cout << "Energy: " << energy << endl;
    cout << "Rest: " << rest << endl;
    cout << "Health: " << health << endl;
}

void checkCalendar(PARAMS) {
    cout << "Let's look at how we're doing..." << endl;
    cout << "Money: " << money << endl;
    if (money < 10) {
        cout << "Uff. Good thing I left enough money to get to work tomorrow." << endl;
    }
    cout << "Date: " << MONTH << " " << day << ", 2000" << endl;
    if (day >= 20) {
        cout << "Hm. I almost can't believe how long it's been." << endl;
    }
    cout << "Time: " << hour << endl;
    if (hour >- 20) {
        cout << "It's getting late. We should sleep soon." << endl;
    }
}

void checkToys(PARAMS) {
    int toyCount = 0;

    cout << "Let's open the shelf." << endl;

    if (toyBallOwned) {
        cout << "There's a ball..." << endl;
        toyCount++;
    }
    if (toyBoxOwned) {
        cout << "We have a cardboard box..." << endl;
        toyCount++;
    }
    if (toySkateOwned) {
        cout << "There's a cool skateboard..." << endl;
        toyCount++;
    }
    if (toyDroneOwned) {
        cout << "That's a super cool drone..." << endl;
    }

    switch (toyCount) {
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

void checkFood(PARAMS) {
    int foodCount = 0;

    cout << "Let's look at our food." << endl;

    if (foodFishCount > 0) {
        cout << "We have " << foodFishCount << " pieces of fish..." << endl;
        foodCount += foodFishCount;
    }
    if (foodPetCount > 0) {
        cout << "We have " << foodPetCount << " servings of pet food..." << endl;
        foodCount += foodPetCount;
    }
    if (foodChickenCount > 0) {
        cout << "We have " << foodChickenCount << " chicken nuggets..." << endl;
        foodCount += foodChickenCount;
    }
    if (foodBeefCount > 0) {
        cout << "We have " << foodBeefCount << " slices of beef..." << endl;
        foodCount += foodBeefCount;
    }

    if (foodCount == 0) {
        cout << "..." << endl;
        cout << "That's not good." << endl;
        cout << "There's nothing." << endl;
        cout << "I should buy some at the store." << endl;
    } else if (foodCount < 2) {
        cout << "I should buy more food soon." << endl;
    } else if (foodCount < 7) {
        cout << "Should be enough for now." << endl;
    } else {
        cout << "Plenty. I don't think I need to buy more unless " << name << " doesn't like what we have." << endl;
    }
}



void play(PARAMS) {
    char choice;
    
    // TODO: reduce energy and rest, increase happiness, increase health
    // if energy or nutrition are too low, decrease health
    // select playthings
}

void feed(PARAMS) {
    // TODO: increase nutrition and energy, decrease rest
    // happiness increases or decreases depending on food chosen
    // select food item depending on money
    // if energy is too high and the pet doesnt like the food, pet will play with food instead, calling play();
    // if nutrition exceeds a threshold, decrease health
    // if rest too low, the pet will refuse to eat
}

void sleep(PARAMS) {
    // TODO: increase energy, happiness, and rest, reduce nutrition
    // if rest too high, decrease energy, health, and happiness instead
    // while pet is sleeping, you can work and earn money to buy food and toys
}

void quit(PARAMS) {
    if (confirm("Are you sure you wanna quit?")) {
        if (confirm("Will you give " + name + " to your neighbor, Kate, instead?")) {
            cout << "Alright then. We'll call her up today, and say goodbye to " << name << " tomorrow." << endl;
            end = 1;
        } else {
            cout << "Then you'll have to stay." << endl;
        }
    } else {
        cout << "I knew it. Who could say no to that little face." << endl;
    }
    pause();
}

// ENDINGS:
// 0 not over
// 1 quit, donate pet to neighbor
// 2 buy drone, the pet drives it home
// 3 happiness goes to 0, pet just leaves you and finds a different owner
// 4 nutrition goes to 0, pet steals your breakfast, leaves, and hangs out with the local cats, hisses at you
// 5 health goes to 0, you call in a vet and they take it into a shelter
// if rest or energy goes to 0, pet sleeps and you are forced into sleep()
void ending(PARAMS) {
    if (end == 0) {
        return;
    }

    cout << "Ah, a good night's sleep." << endl;
    prompt('G', "ood morning.");
    switch (end) {
        // should've been caught earlier
        case 0:
            error();
            return;
        
        // quit
        case 1:
            cout << "You donated your pet to your neighbor Kate." << endl;
            prompt('Y', "eah...");
            cout << "She'll take good care of " << name << ". It's a promise." << endl;
            pause();
            cout << "Rest easy. You still have the rest of your vacation." << endl;
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

void error() {
    cout << "AN ERROR OCCURRED RIP" << endl;
    pause();
}
