#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
//THIS IS A DATATYPE NOW HAS STRING AND INT
candidate;

// Array of candidates
//DEFINING AN ARRAY
//FIRST 'CANDIDATE' IS A DATATYPE
//SECOND 'CANDIDATE' IS THE NAME OF THE ARRAY,
//THE MAX NUMBER ALLOWED IN THE ARRAY IS DEFINED ABOVE ('#DEFINE MAX 9')
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
//VOTE FUNCTION REQUIRES NAME AS USER INPUT
//OUPUT IS TRUE OR FALSE
bool vote(string name);
//DOESN'T OUTPUT ANYTHING
void print_winner(void);

//HAS COMMAND LINE ARGUMENT ABILITY
int main(int argc, string argv[])
{
    // Check for invalid usage
    //CAN'T HAVE LESS THAN TWO CANDIDATES IN COMMAND LINE FOR A VOTE
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    //TO SEPARATE CANDITATES FROM './PLURALITY'
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    //THIS IS A LOOP CHECKING THE CANDIDATES
    for (int i = 0; i < candidate_count; i++)
    {
        //'ARGV [0]' IS './PLURALITY'
        //SO THIS HAS TO START AT THE SECOND ARGV WHICH IS WHY IT'S 'ARGV [I + 1]'
        candidates[i].name = argv[i + 1];
        //THESE ARE THE STARTING AMOUNT OF VOTES
        candidates[i].votes = 0;
    }
    //ASKING USER HOW MANY VOTERS THERE ARE
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    //ASKING ALL VOTERS WHO THEY VOTE FOR
    for (int i = 0; i < voter_count; i++)
    {
        //ASKING FOR INPUT OF CANDIDATE NAME
        string name = get_string("Vote: ");

        // Check for invalid vote
        //IF CANDIDATE NAME ISN'T THE ONE VOTED FOR/ TYPED AT THE PROMPT
        //NEED TO WRITE THIS
        if (!vote(name))
        {
            //IT'S INVALID AND USER IS TOLD
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    //NEED TO WRITE THIS FUNCTION
    print_winner();
}

// Update vote totals given a new vote
//IF ONE OF THE CANDIDATES IS VOTED FOR, RETURN TRUE
bool vote(string name)
{
    //LOOP THROUGH CANDIDATES WITH FOR LOOP
    //FOR ANY TIME THE CANDIDATE IS VOTED FOR, ADD TO 'I'
    for (int i = 0; i < candidate_count; i++)
    {
        //IF NAME THAT USER TYPED MATCHES - LOOP
        //IF NAME TYPED IS EQUAL TO A CANDIDATE NAME, INCREASE VOTE TOTAL
        // CAN'T USE "if (name == candidates[i].name)" AS IT COMPARES INT ONLY...
        //I CAN CONVERT NAMES TO AN ASSIGNED INT OR USE STRCMP()
        //COMPARING NAME AND CANDIDATES NAME, IF THEY ARE EQUIVALENT THEN ADD TO CANDIDATES' TOTAL
        if (strcmp(name, candidates[i].name) == 0)
        {
            //THEN UPDATE VOTE COUNT TOTAL
            candidates[i].votes++;
            return true;
        }

    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //NEED CONTAINER TO HOLD MOST VOTES
    int most_votes = 0;
    // PRINT WHOEVER HAS MOST VOTES
    //FIND HIGHEST NUMBER OF VOTES FIRST
    //COMPARE EACH CANDIDATE WITH EACH OTHER WITH LOOP
    for (int i = 0; i < candidate_count ; i++)

    {
        //NEED TO REPLACE MOSTVOTES VARIABLE WITH LARGEST NUMBER FOUND
        if (candidates[i].votes > most_votes)
        {
            //THIS IS REPLACMENT METHOD ASSIGNMENT OF MOST_VOTES NUMBER
            most_votes = candidates[i].votes;
        }
    }
    //NEED TO GO THROUGH ALL CANDIDATES AGAIN
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == most_votes)
        {
            printf("%s\n", candidates[i].name);
        }


    }
    return;

}