#include "header.h"
#include "adding_station.h"


char **purple_line = NULL;
char **green_line = NULL;
int size;
int capacity;
int prev;

void initial(int *opt)
{
    if(*opt == 1)
    {
        // Purple
        capacity = V_N;
        size = V_N;
        purple_line = malloc(capacity * sizeof(char*));
        if(purple_line == NULL)
        {
            printf("Memory allocation failed!\n");
            return ;
        }
        char *initial_stat[] = {"Challaghatta", "Kengeri", "Kengeri Bus Terminal", "Pattanagere", "Jnanabharathi", 
        "Rajarajeshwari Nagar", "Nayandahalli", "Mysuru Road", "Deepanjali Nagar", "Attiguppe", "Vijayanagar", "Hosahalli", 
        "Magadi Road", "KSR City Railway Stn.", "Majestic", "Central College", "Vidhana Soudha", "Cubbon Park", "Mahatma Gandhi Road", 
        "Trinity","Halasuru", "Indiranagar", "Swami Vivekananda Road", "Baiyappanahalli", "Benniganahalli", "KR Pura", "Singayyanapalya", 
        "Garudacharpalya", "Hoodi", "Seetharam Palya", "Kundalahalli", "Nallurhalli", "Sri Sathya Sai Hospital", "Pattandur Agrahara", 
        "Kadugodi Tree Park", "Hopefarm", "Whitefield"};
        for (int i = 0; i < size; i++)
        {
            purple_line[i] =  malloc((strlen(initial_stat[i]) + 1) * sizeof(char));
            if (purple_line[i] == NULL)
            {
                printf("Memory allocation failed for station %d\n", i);
                for (int j = 0; j < i; j++)
                {
                    free(purple_line[j]);
                }
                free(purple_line);
                return ;
            }
            strcpy(purple_line[i], initial_stat[i]);
        }
    }
    else if(*opt == 2)
    {
        // Green
        capacity = G_N;
        size = G_N;
        green_line = malloc(capacity * sizeof(char*));
        if(green_line == NULL)
        {
            printf("Memory allocation failed!\n");
            return ;
        }
        // ginitial_setting(initial_stat);
        char *initial_stat[] = {"Silk Institute", "Thalaghattapura", "Vajarahalli", "Doddakallasandra", "Konanakunte Cross", 
        "Yelachenahalli", "Jayaprakash Nagar", "Banaskankari", "Rashtreeya Vidyalaya Road", "Jayanagar",
        "South End Circle", "Lalbagh", "Krishna Rajendra Market", "Chickpete", "Majestic", "Sampige Road", "Srirampura", 
        "Rajajinagar", "Kuvempu Road", "Mahalakshmi", "Sandal Soap Factory", "Yeshwantpur", "Goraguntepalya", "Peenya", 
        "Peenya Industry", "Jalahalli", "Dasarahalli", "Nagasandra", "Manjunathanagar", "Chikkabidarakallu", "Madavara"};
        for (int i = 0; i < size; i++)
        {
            green_line[i] =  malloc((strlen(initial_stat[i]) + 1) * sizeof(char));
            if (green_line[i] == NULL)
            {
                printf("Memory allocation failed for station %d\n", i);
                for (int j = 0; j < i; j++)
                {
                    free(green_line[j]);
                }
                free(green_line);
                return ;
            }
            strcpy(green_line[i], initial_stat[i]);
        }
    }
}