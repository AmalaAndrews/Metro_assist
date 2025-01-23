#include "header.h"
#include "adding_station.h"


char **route_line = NULL;
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
        route_line = (char*) malloc(capacity * sizeof(char*));
        if(route_line == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
        char *initial_stat[] = {"Silk Institute", "Thalaghattapura", "Vajarahalli", "Doddakallasandra", "Konanakunte Cross", 
        "Yelachenahalli", "Jayaprakash Nagar", "Banaskankari", "Rashtreeya Vidyalaya Road", "Jayanagar", "Jayanagar", 
        "South End Circle", "Lalbagh", "Krishna Rajendra Market", "Chickpete", "Majestic", "Sampige Road", "Srirampura", 
        "Rajajinagar", "Kuvempu Road", "Mahalakshmi", "Sandal Soap Factory", "Yeshwantpur", "Goraguntepalya", "Peenya", 
        "Peenya Industry", "Jalahalli", "Dasarahalli", "Nagasandra", "Manjunathanagar", "Chikkabidarakallu", "Madavara"};
        for (int i = 0; i < size; i++)
        {
            route_line[i] = (char) malloc((strlen(initial_stat[i]) + 1) * sizeof(char));
            strcpy(route_line[i], initial_stat[i]);
        }
    }
    else if(opt == 2)
    {
        // Green
        capacity = G_N;
        size = G_N;
        route_line = (char*) malloc(capacity * sizeof(char*));
        if(route_line == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
        // ginitial_setting(initial_stat);
        char *initial_stat[] = {"Challaghatta", "Kengeri", "Kengeri Bus Terminal", "Pattanagere", "Jnanabharathi", 
        "Rajarajeshwari Nagar", "Nayandahalli", "Mysuru Road", "Deepanjali Nagar", "Attiguppe", "Vijayanagar", "Hosahalli", 
        "Magadi Road", "KSR City Railway Stn.", "Majestic", "Central College", "Vidhana Soudha", "Cubbon Park", "Mahatma Gandhi Road", 
        "Trinity","Halasuru", "Indiranagar", "Swami Vivekananda Road", "Baiyappanahalli", "Benniganahalli", "KR Pura", "Singayyanapalya", 
        "Garudacharpalya", "Hoodi", "Seetharam Palya", "Kundalahalli", "Nallurhalli", "Sri Sathya Sai Hospital", "Pattandur Agrahara", 
        "Kadugodi Tree Park", "Hopefarm", "Whitefield"};
        for (int i = 0; i < size; i++)
        {
            route_line[i] = (char) malloc((strlen(initial_stat[i]) + 1) * sizeof(char));
            strcpy(route_line[i], initial_stat[i]);
        }
    }
}