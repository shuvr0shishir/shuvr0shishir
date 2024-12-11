#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

#define NUM_DHAKA 13      //
#define NUM_CHATTOGRAM 11 //
#define NUM_KHULNA 10     //
#define NUM_RAJSHAHI 8    //
#define NUM_BARISHAL 6    //
#define NUM_SYLHET 4      //
#define NUM_RANGPUR 8     //
#define NUM_MYMENSINGH 4
#define INF 999999

int div = 0;
/// Function Declarations
int dijkstra(int costMatrix[div][div], int NUM, int src, int dest,char **districts);

void toUpperCase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]); // Convert each character to uppercase
    }
}
int Find_district(char *divis[div], char input[50], int size)
{
    char source[50];
    strcpy(source, input);
    toUpperCase(source);
    char dest[50];
    for (int i = 0; i < size; i++)
    {
        strcpy(dest, divis[i]);
        toUpperCase(dest);
        if (strcmp(source, dest) == 0)
        {
            return i;
        }
    }
    return -1;
}
int division1(char str[50])
{
    char *dhakaDivision[NUM_DHAKA] = {
        "Dhaka", "Gazipur", "Kishoreganj", "Manikganj",
        "Munshiganj", "Narayanganj", "Narsingdi",
        "Tangail", "Faridpur", "Gopalganj", "Madaripur",
        "Rajbari", "Shariatpur"};

    int dhakaCostMatrix[NUM_DHAKA][NUM_DHAKA] = {
        {0, 20, 10, 30, INF, INF, 50, 70, 90, INF, INF, 30, INF},        // Dhaka
        {20, 0, INF, 15, 25, INF, INF, INF, INF, INF, INF, INF, INF},    // Madaripur
        {10, INF, 0, 25, INF, INF, INF, INF, 40, INF, INF, INF, INF},    // Manikganj
        {30, 15, 25, 0, 40, 50, 60, INF, 20, INF, INF, INF, INF},        // Munshiganj
        {INF, 25, INF, 40, 0, 30, INF, 20, INF, INF, INF, INF, INF},     // Narayanganj
        {INF, INF, INF, 50, 30, 0, 25, INF, 60, INF, INF, INF, INF},     // Narsingdi
        {50, INF, INF, 60, INF, 25, 0, INF, INF, INF, INF, INF, INF},    // Rajbari
        {70, INF, INF, INF, 20, INF, INF, 0, INF, INF, INF, INF, INF},   // Shariatpur
        {90, INF, 40, 20, INF, 60, INF, INF, 0, INF, INF, INF, INF},     // Tangail
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF}, // Madaripur
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF}, // Keraniganj
        {30, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF},  // Gazipur
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0}  // Kishoreganj
    };
    div = NUM_DHAKA;
    int found = Find_district(dhakaDivision, str, NUM_DHAKA);
    if (found != -1)
    {
        int dest = dijkstra(dhakaCostMatrix, NUM_DHAKA, 0, found,dhakaDivision);
        printf("Dest = %d\n", dest);
        return dest;
    }
    else
    {
        return -1;
    }
}

int division2(char str[50])
{
    char *chattogramDivision[NUM_CHATTOGRAM] = {
        "Chattogram", "Bandarban", "Brahmanbaria", "Chandpur",
        "Cox's Bazar", "Cumilla", "Feni", "Khagrachari",
        "Lakshmipur", "Noakhali", "Rangamati"};

    // Sample cost matrix (distance in kilometers or cost between districts)
    int costMatrix[NUM_CHATTOGRAM][NUM_CHATTOGRAM] = {
        {0, 150, 80, 120, 110, 130, 100, INF, 90, 160, 200},   // Chittagong
        {150, 0, 100, 140, 120, 160, 180, INF, 110, 170, 210}, // Cox's Bazar
        {80, 100, 0, 60, 50, 90, 70, INF, 60, 120, 160},       // Cumilla
        {120, 140, 60, 0, 40, 70, 60, INF, 30, 100, 140},      // Chandpur
        {110, 120, 50, 40, 0, 50, 40, INF, 20, 90, 120},       // Lakshmipur
        {130, 160, 90, 70, 50, 0, 80, INF, 70, 140, 170},      // Noakhali
        {100, 180, 70, 60, 40, 80, 0, INF, 60, 110, 140},      // Feni
        {INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF}, // Khagrachari
        {90, 110, 60, 30, 20, 70, 60, INF, 0, 60, 90},         // Brahmanbaria
        {160, 170, 120, 100, 90, 140, 110, INF, 60, 0, 80},    // Rangamati
        {200, 210, 160, 140, 120, 170, 140, INF, 90, 80, 0}    // Bandarban
    };
    div = NUM_CHATTOGRAM;
    int found = Find_district(chattogramDivision, str, NUM_CHATTOGRAM);
    if (found != -1)
    {
        int dest = dijkstra(costMatrix, NUM_CHATTOGRAM, 0, found,chattogramDivision);
        printf("Dest = %d\n", dest);
        return dest;
    }
    else
    {
        return -1;
    }
}

int division3(char str[50])
{
    char *rajshahiDivision[NUM_RAJSHAHI] = {
        "Rajshahi", "Bogra", "Chapainawabganj", "Joypurhat",
        "Naogaon", "Natore", "Pabna", "Sirajganj"};

    // Sample cost matrix (distance or cost between districts)
    int costMatrix[NUM_RAJSHAHI][NUM_RAJSHAHI] = {
        // Rajshahi, Bogra, Chapainawabganj, Joypurhat, Naogaon, Natore, Pabna, Sirajganj
        {0, 80, 100, 50, INF, INF, 110, 130},   // Rajshahi
        {80, 0, 60, 70, 90, INF, 80, 100},      // Bogura
        {100, 60, 0, 90, 60, INF, 110, 120},    // Naogaon
        {50, 70, 90, 0, 140, 160, 120, 130},    // Pabna
        {INF, 90, 60, 140, 0, 150, 130, 140},   // Chapai Nawabganj
        {INF, INF, INF, 160, 150, 0, 140, 150}, // Joypurhat
        {110, 80, 110, 120, 130, 140, 0, 100},  // Natore
        {130, 100, 120, 130, 140, 150, 100, 0}  // Sirajganj
    };
    div = NUM_RAJSHAHI;
    int found = Find_district(rajshahiDivision, str, NUM_RAJSHAHI);
    if (found != -1)
    {
        int dest = dijkstra(costMatrix, NUM_RAJSHAHI, 0, found,rajshahiDivision);
        printf("Dest = %d\n", dest);
        return dest;
    }
    else
    {
        return -1;
    }
}

int division4(char str[50])
{
    char *barishalDivision[NUM_BARISHAL] = {
        "Barishal", "Barguna", "Bhola", "Jhalokati", "Patuakhali", "Pirojpur"};

    // Sample cost matrix (distance or cost between districts)
    int costMatrix[NUM_BARISHAL][NUM_BARISHAL] = {
        // Barishal, Barguna, Bhola, Jhalokati, Patuakhali, Pirojpur
        {0, 120, 80, INF, 110, 90},  // Barishal
        {120, 0, 150, 130, 90, 140}, // Barguna
        {80, 150, 0, 70, 100, 120},  // Bhola
        {INF, 130, 70, 0, 90, 60},   // Jhalokati
        {110, 90, 100, 90, 0, 130},  // Patuakhali
        {90, 140, 120, 60, 130, 0}   // Pirojpur
    };
    div = NUM_BARISHAL;
    int found = Find_district(barishalDivision, str, NUM_BARISHAL);
    if (found != -1)
    {
        int dest = dijkstra(costMatrix, NUM_BARISHAL, 0, found,barishalDivision);
        printf("Dest = %d\n", dest);
        return dest;
    }
    else
    {
        return -1;
    }
}

int division5(char str[50])
{
    char *khulnaDivision[NUM_KHULNA] = {
        "Khulna", "Bagerhat", "Chuadanga", "Jessore",
        "Jhenaidah", "Kushtia", "Magura", "Meherpur",
        "Narail", "Satkhira"};

    // Sample cost matrix (distance or cost between districts)
    int costMatrix[NUM_KHULNA][NUM_KHULNA] = {
        // Khulna, Bagerhat, Chuadanga, Jessore, Jhenaidah, Kushtia, Magura, Meherpur, Narail, Satkhira
        {0, 50, 110, INF, 120, INF, 100, 150, 80, 60}, // Khulna
        {50, 0, 150, 120, 140, 160, 110, 170, 90, 70}, // Bagerhat
        {110, 150, 0, 100, 90, 80, 60, 70, 120, 130},  // Chuadanga
        {INF, 120, 100, 0, 60, 70, 50, 100, 70, 80},   // Jessore
        {120, 140, 90, 60, 0, 80, 40, 90, 90, 110},    // Jhenaidah
        {INF, 160, 80, 70, 80, 0, 70, 60, 100, 150},   // Kushtia
        {100, 110, 60, 50, 40, 70, 0, 80, 60, 120},    // Magura
        {150, 170, 70, 100, 90, 60, 80, 0, 130, 160},  // Meherpur
        {80, 90, 120, 70, 90, 100, 60, 130, 0, 70},    // Narail
        {60, 70, 130, 80, 110, 150, 120, 160, 70, 0}   // Satkhira
    };
    div = NUM_KHULNA;
    int found = Find_district(khulnaDivision, str, NUM_KHULNA);
    if (found != -1)
    {
        int dest = dijkstra(costMatrix, NUM_KHULNA, 0, found,khulnaDivision);
        printf("Dest = %d\n", dest);
        return dest;
    }
    else
    {
        return -1;
    }
}

int division6(char str[50])
{
    char *sylhetDivision[NUM_SYLHET] = {
        "Sylhet", "Moulvibazar", "Habiganj", "Sunamganj"};

    // Sample cost matrix (distance or cost between districts)
    int costMatrix[NUM_SYLHET][NUM_SYLHET] = {
        // Sylhet, Moulvibazar, Habiganj, Sunamganj
        {0, 60, 70, 90},   // Sylhet
        {60, 0, INF, 100}, // Moulvibazar
        {70, INF, 0, 80},  // Habiganj
        {90, 100, 80, 0}   // Sunamganj
    };
    div = NUM_SYLHET;
    int found = Find_district(sylhetDivision, str, NUM_SYLHET);
    if (found != -1)
    {
        int dest = dijkstra(costMatrix, NUM_SYLHET, 0, found,sylhetDivision);
        printf("Dest = %d\n", dest);
        return dest;
    }
    else
    {
        return -1;
    }
}

int division7(char str[50])
{
    char *rangpurDivision[NUM_RANGPUR] = {
        "Rangpur", "Dinajpur", "Thakurgaon", "Panchagarh",
        "Kurigram", "Gaibandha", "Nilphamari", "Lalmonirhat"};

    // Sample cost matrix (distance or cost between districts)
    int costMatrix[NUM_RANGPUR][NUM_RANGPUR] = {
        // Rangpur, Dinajpur, Thakurgaon, Panchagarh, Kurigram, Gaibandha, Nilphamari, Lalmonirhat
        {0, 70, INF, 110, 80, INF, 50, 40},   // Rangpur
        {70, 0, 60, 80, 120, 90, 100, 110},   // Dinajpur
        {INF, 60, 0, 50, 140, 110, 120, 130}, // Thakurgaon
        {110, 80, 50, 0, 160, 130, 140, 150}, // Panchagarh
        {80, 120, 140, 160, 0, 70, 90, 60},   // Kurigram
        {INF, 90, 110, 130, 70, 0, 40, 50},   // Gaibandha
        {50, 100, 120, 140, 90, 40, 0, 60},   // Nilphamari
        {40, 110, 130, 150, 60, 50, 60, 0}    // Lalmonirhat
    };
    div = NUM_RANGPUR;
    int found = Find_district(rangpurDivision, str, NUM_RANGPUR);
    if (found != -1)
    {
        int dest = dijkstra(costMatrix, NUM_RANGPUR, 0, found,rangpurDivision);
        printf("Dest = %d\n", dest);
        return dest;
    }
    else
    {
        return -1;
    }
}

int division8(char str[50])
{
    char *mymensinghDivision[NUM_MYMENSINGH] = {
        "Mymensingh", "Jamalpur", "Netrokona", "Sherpur"};

    // Sample cost matrix (distance or cost between districts)
    int costMatrix[NUM_MYMENSINGH][NUM_MYMENSINGH] = {
        // Mymensingh, Jamalpur, Netrokona, Sherpur
        {0, 70, INF, 80},  // Mymensingh
        {70, 0, 90, 50},   // Jamalpur
        {INF, 90, 0, 100}, // Netrokona
        {80, 50, 100, 0}   // Sherpur
    };
    div = NUM_MYMENSINGH;
    int found = Find_district(mymensinghDivision, str, NUM_MYMENSINGH);
    if (found != -1)
    {
        int dest = dijkstra(costMatrix, NUM_MYMENSINGH, 0, found,mymensinghDivision);
        printf("Dest = %d\n", dest);
        return dest;
    }
    else
    {
        return -1;
    }
}

int main()
{
    while (1)
    {
        system("cls");
        printf("[1]Find Shortest Path From DSC\n");
        printf("[2]Sort All The Districts\n");
        printf(">>");
        int ch;
        scanf("%d", &ch);

        if (ch == 1)
        {
            char input[50];
            printf("Enter Destination:\n");
            scanf("%s", input);
            int (*division[])(char[50]) = {
                division1, division2, division3, division4,
                division5, division6, division7, division8};

            int dist[] = {20, 100, 150, 200, 300, 250, 175, 79};
            char *dist_name[] = {"Dhaka", "Chittagong", "Rajshahi", "Barishal", "Khulna", "Sylhet", "Rangpur", "Mymenshingh"};
            int result = -1;
            for (int i = 0; i < 8; i++)
            {
                result = division[i](input);
                if (result != -1)
                {
                    printf("Distance From DSC to %s is : %d\n", input, result + dist[i]);
                    printf("\nTime Taken From DSC to %s is : %d Hour %d Minutes\n", input, ((result + dist[i]) * 5)/60,((result + dist[i]) * 5)%60);
                    printf("\n%s is Under The division %s\n", input, dist_name[i]);
                    break;
                }
            }
            if (result == -1)
            {
                printf("Invalid Input\n");
            }
        }
        else if (ch == 2)
        {
            print_all();
        }
        else
        {
        }

        fflush(stdin);
        getchar();
    }
}
void print_all()
{
    // Array of strings containing all the districts of Bangladesh
    char *allDistricts[] = {
        "Dhaka", "Faridpur", "Gazipur", "Gopalganj", "Kishoreganj", "Madaripur", "Manikganj",
        "Munshiganj", "Mymensingh", "Narayanganj", "Narsingdi", "Netrokona", "Shariatpur",
        "Tangail", "Thakurgaon", "Chittagong", "Bandarban", "Brahmanbaria", "Chandpur", "Comilla", "Cox's Bazar",
        "Feni", "Khagrachari", "Lakshmipur", "Noakhali", "Rangamati", "Rajshahi", "Bogura", "Naogaon", "Pabna", "Chapai Nawabganj", "Joypurhat", "Natore",
        "Sirajganj", "Khulna", "Bagerhat", "Chuadanga", "Jessore", "Jhenaidah", "Khulna", "Kushtia",
        "Meherpur", "Mongla", "Satkhira", "Shariatpur",
        "Barishal", "Patuakhali", "Barguna", "Bhola", "Jhalokathi", "Pirojpur",
        "Sylhet", "Moulvibazar", "Habiganj", "Sunamganj",
        "Rangpur", "Kurigram", "Gaibandha", "Lalmonirhat", "Nilphamari", "Panchagarh", "Dinajpur",
        "Thakurgaon", "Rangpur",
        "Mymensingh"};
    int n = sizeof(allDistricts) / sizeof(allDistricts[0]); // Number of districts

    // Bubble sort to sort the array alphabetically
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(allDistricts[j], allDistricts[j + 1]) > 0)
            { // Compare strings
                // Swap districts
                char *temp = allDistricts[j];
                allDistricts[j] = allDistricts[j + 1];
                allDistricts[j + 1] = temp;
            }
        }
    }

    // Print the sorted list of districts
    printf("Sorted list of districts:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", allDistricts[i]);
    }
}
int findMinDistance(int *dist, int *visited, int NUM)
{
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < NUM; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int dijkstra(int costMatrix[div][div], int NUM, int src, int dest,char **districts)
{
    // Dynamically allocate memory for dist and visited arrays
    int *dist = (int *)malloc(NUM * sizeof(int));   // Array to store the shortest distance
    int *visited = (int *)calloc(NUM, sizeof(int)); // Array to keep track of visited nodes

    // Initialize distances
    for (int i = 0; i < NUM; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Find shortest path for all districts
    for (int count = 0; count < NUM - 1; count++)
    {
        int u = findMinDistance(dist, visited, NUM); // Pick the minimum distance vertex
        visited[u] = 1;

        // Update distance of adjacent districts
        for (int v = 0; v < NUM; v++)
        {
            if (!visited[v] && costMatrix[u][v] && dist[u] != INT_MAX && dist[u] + costMatrix[u][v] < dist[v])
            {
                dist[v] = dist[u] + costMatrix[u][v];
            }
        }
    }
    
    int result = dist[dest];
    // Clean up the dynamically allocated memory
    free(dist);
    free(visited);

    if (result != INT_MAX)
    {
        return result; // Path found
    }
    else
    {
        return -1; // No path to destination
    }
}