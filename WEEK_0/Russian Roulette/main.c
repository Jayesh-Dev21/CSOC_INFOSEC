#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_BULLETS 6
#define MAX_BOTS 5
typedef long long ll;
typedef struct{
    int chamber[MAX_BULLETS];
} Gun;

typedef struct{
    char name[50];
    ll money;
    int is_alive;
} Player;

void banner(const char *title) {
    printf("\n=========================================================================\n");
    char command[512];
    snprintf(command, sizeof(command), "python3 python_scripts/banner.py \"%s\"", title);
    system(command);
    printf("=========================================================================\n");
}

int randomize(int max){
    return rand() % (max + 1);
}

void shuffle_chamber(int *array, int size){
    srand(time(NULL));
    for(int i = size - 1; i > 0; i--){
        int j = randomize(i);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int number_of_bullets_count(int size){
    srand(time(NULL));
    int bullets = randomize(MAX_BULLETS);
    while(0 == bullets){
        bullets = randomize(MAX_BULLETS);
    }
    return bullets;
}

void initialize_player(Player *localplayer){
    printf("Enter your name: ");
    fgets(localplayer->name, sizeof(localplayer->name), stdin);
    localplayer->name[strcspn(localplayer->name, "\n")] = 0;
    localplayer->money = 0;
    localplayer->is_alive = 1;
}

int menu(Player *localplayer){
    int retVal;
    printf("Welcome to Russian Roulette, %s!\n", localplayer->name);
    printf("\t\t\t\t\t\t\tYou have $%lld.\n", localplayer->money);
    printf("0. Help\n");
    printf("1. Play\n");
    printf("2. Start New Game\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &retVal);
    getchar();
    return retVal;
}

void playerStats(Player *localplayer){
    printf("Player Name: %s\n", localplayer->name);
    printf("\t\t\t\t\t\t\tYou Made: $%lld\n", localplayer->money);
}

void help(){
    banner("HELP");
    printf("🎲 Russian Roulette -> A Game of Chance, Guts, and Glory 🎲\n");
    printf("=========================================================================\n");
    printf("🧠 Objective:\n");
    printf("   Survive the chamber. Outlast the bots. Earn money with every\n");
    printf("   pull of the trigger — but beware, one mistake ends it all.\n\n");
    printf("🔫 How It Works:\n");
    printf("   - A revolver with 6 chambers is loaded with a random number of bullets.\n");
    printf("   - Chambers are shuffled before every round.\n");
    printf("   - Players take turns pulling the trigger in random order.\n");
    printf("   - Survive to earn money; a bullet means elimination.\n\n");
    printf("🎮 Menu Options:\n");
    printf("   0. Help         -> You're reading it!\n");
    printf("   1. Play         -> Enter the game. Spin the cylinder. Take the risk.\n");
    printf("   2. New Game     -> Reset progress and start fresh.\n");
    printf("   3. Exit         -> Walk away (with your head still attached).\n\n");
    printf("💰 Rewards:\n");
    printf("   - Surviving a shot earns you $1000.\n");
    printf("   - Outlasting bots increases your earnings.\n\n");
    printf("⚠️ Warning:\n");
    printf("   This game is for virtual thrills only.\n");
    printf("   Don't try this in real life — seriously.\n");
    banner("HELP");
}

void display_chamber(int a, int b){
    banner("Gun Chamber");
    printf("The chamber of the gun has %d slots,\nOut of which there are %d bullets arranged randomly inside the chamber\n", b, a);
    char bullet_display[2*MAX_BULLETS];
    for(int i = 0; i < a; i++){
        bullet_display[2*i] = '*';
        bullet_display[2*i+1] = ' ';
    }
    for(int i = a; i < b; i++){
        bullet_display[2*i] = '_';
        bullet_display[2*i+1] = ' ';
    }
    bullet_display[2*b] = '\0';
    banner(bullet_display);
}

void initialize_bots(Player *bots, int number_of_bots) {
    const char *bot_names[] = {"Bot-on", "Bot-cat", "Bot-lee", "Bot-cow", "Bot-rry"};
    for (int i = 0; i < number_of_bots; i++) {
        strncpy(bots[i].name, bot_names[i], sizeof(bots[i].name) - 1);
        bots[i].name[sizeof(bots[i].name) - 1] = '\0';
        bots[i].money = 0;
        bots[i].is_alive = 1;
    }
}

int count_alive_players(Player *player, Player *bots, int number_of_bots) {
    int alive = player->is_alive ? 1 : 0;
    for (int i = 0; i < number_of_bots; i++) {
        if (bots[i].is_alive) alive++;
    }
    return alive;
}

void shuffle_players(int *order, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = randomize(i);
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }
}

void play_round(Player *player, Player *bots, int number_of_bots, Gun *gun, int *chamber_index) {
    int total_players = number_of_bots + 1;
    int order[total_players];
    for (int i = 0; i < total_players; i++) order[i] = i;

    shuffle_players(order, total_players);

    printf("\nTurn order this round:\n");
    for (int i = 0; i < total_players; i++) {
        if (order[i] == 0 && player->is_alive) {
            printf("%s ", player->name);
        } else if (bots[order[i] - 1].is_alive) {
            printf("%s ", bots[order[i] - 1].name);
        }
    }
    printf("\n");

    for (int i = 0; i < total_players && *chamber_index < MAX_BULLETS; i++) {
        if (order[i] == 0 && player->is_alive) {
            printf("\n%s pulls the trigger...\n", player->name);
            sleep(1);
            if (gun->chamber[*chamber_index]) {
                printf("BANG! %s is out!\n", player->name);
                player->is_alive = 0;
            } else {
                printf("Click! %s survives and earns $1000!\n", player->name);
                player->money += 1000;
            }
        } else if (bots[order[i] - 1].is_alive) {
            printf("\n%s pulls the trigger...\n", bots[order[i] - 1].name);
            sleep(1);
            if (gun->chamber[*chamber_index]) {
                printf("BANG! %s is out!\n", bots[order[i] - 1].name);
                bots[order[i] - 1].is_alive = 0;
            } else {
                printf("Click! %s survives.\n", bots[order[i] - 1].name);
                bots[order[i] - 1].money += 1000;
            }
        }
        (*chamber_index)++;
        if (*chamber_index >= MAX_BULLETS) {
            printf("\nChamber is empty. Reloading for next round...\n");
            break;
        }
        sleep(1);
    }
}

void play(Player *player){
    Gun gun = {0};
    initialize_player(player);
    srand(time(NULL));

    

    while(1){
        int choice = menu(player);

        int number_of_bullets = number_of_bullets_count(MAX_BULLETS);
        for (int i = 0; i < number_of_bullets; i++) {
            gun.chamber[i] = 1;
        }

        int number_of_bots = randomize(500000) % MAX_BOTS;
        while (number_of_bots == 0) {
            number_of_bots = randomize(500000) % MAX_BOTS;
        }

        Player *bots = malloc(sizeof(Player) * number_of_bots);
        if (!bots) {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        if (choice == 2) {
            playerStats(player);
            free(bots);
            banner("New Game");
            printf("Starting a new game...\n");
            play(player);
            continue;
        } else if (choice == 3) {
            printf("Exiting...\n");
            playerStats(player);
            banner("Goodbye");
            exit(0);
        } else if (choice == 0) {
            help();
            continue;
        } else if (choice != 1) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("You chose to play!\n");
        
        sleep(1);
        banner("Bots are loading");
        printf("Loading bots...\n");
        sleep(1);
        printf("Bots loaded: %d%%\n", (randomize(100) + randomize(200) + randomize(69)) % 100);
        sleep(1);
        printf("All bots loaded!\n");
        printf("You will be playing against %d bots.\n", number_of_bots);

    
        initialize_bots(bots, number_of_bots);

        sleep(1);
        display_chamber(number_of_bullets, MAX_BULLETS);
        shuffle_chamber(gun.chamber, MAX_BULLETS);

        int chamber_index = 0;
        while (count_alive_players(player, bots, number_of_bots) > 1 && chamber_index < MAX_BULLETS) {
            play_round(player, bots, number_of_bots, &gun, &chamber_index);
            if (chamber_index >= MAX_BULLETS) {
                printf("Reloading chamber...\n");
                chamber_index = 0;
                for (int i = 0; i < MAX_BULLETS; i++) gun.chamber[i] = 0;
                number_of_bullets = number_of_bullets_count(MAX_BULLETS);
                for (int i = 0; i < number_of_bullets; i++) gun.chamber[i] = 1;
                shuffle_chamber(gun.chamber, MAX_BULLETS);
                display_chamber(number_of_bullets, MAX_BULLETS);
            }
        }

        if (player->is_alive && count_alive_players(player, bots, number_of_bots) == 1) {
            printf("\nCongratulations, %s! You are the last survivor!\nAnd Here's your $1000 bonus for surviving", player->name);
            player->money += 5000; // Bonus 
            banner("Vicory");
        } else if (!player->is_alive) {
            printf("\nGame over! You didn't survive.\n");
            banner("Game Over");
        } else {
            printf("\nGame ended with multiple survivors.\n");
        }

        free(bots);
        printf("Would you like to play again?\n");
        printf("1. YES\n");
        printf("2. NO\n");
        int cc;
        scanf("%d", &cc);
        getchar();
        if (cc == 2 || cc != 1) {
            printf("Exiting...\n");
            playerStats(player);
            banner("Goodbye");
            exit(0);
        }
    }
}

int main(void){
    banner("Russian Roulette");
    Player localplayer;
    play(&localplayer);
    return 0;
}