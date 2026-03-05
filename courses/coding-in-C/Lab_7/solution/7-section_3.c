#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--------------------------------------------------------------------------------------------------*/
/*-------------------------------------Songs--------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
//wie sieht ein Song aus
typedef struct Song
{
    char* caartist; //Künstlername als Char Pointer
    char* catitle;  //Songtitel als Char Pointer

    struct Song* pnext; //pnext Structure Pointer für verkettete Liste
}Song;

/*--------------------------------------------------------------------------------------------------*/
//Song erstellen

Song* createSong(const char *artist, const char *title) // der Song bekommt die unveränderbaren char Pointer Artist und title mit
{
    Song* NewSong = malloc(sizeof(NewSong));            //der neue song hat die größe des neuen Songs
    if (!NewSong) return NULL;                          //falls es scheitert, direkter return

    // Speicher für Artist kopieren
    NewSong->caartist = malloc(strlen(artist) + 1);     //
    if (!NewSong->caartist) 
    {
        free(NewSong);
        return NULL;
    }


    strcpy(NewSong->caartist, artist);

    // Speicher für Title kopieren

    NewSong->catitle = malloc(strlen(title) + 1);
    if (!NewSong->catitle) 
    {
        free(NewSong->caartist);
        free(NewSong);
        return NULL;
    }
    strcpy(NewSong->catitle, title);

    NewSong->pnext = NULL;

    return NewSong;
}

Song* InsertAtBack(Song* head,const char *artist, const char *title)
    {
        Song* NewSong = createSong(artist, title);
        if (!NewSong) return head;
        if (head == NULL) { return NewSong; } 
    

        Song* curr= head;
        
        while(curr->pnext!=NULL)
        {
            curr=curr->pnext;
        }

    
        curr->pnext=NewSong;
        return head;
    }
        
//Mehr Knoten erstellen

/*--------------------------------------------------------------------------------------------------*/
/*---------------------------------Playlist---------------------------------------------------------*/

typedef struct Playlist         //playlist erstellen
{
    Song* head;
    int count;
} Playlist;

void initPlaylist(Playlist* pl)     //playlist wird intialisiert mit einem Playlist pointer
{
    pl->head = NULL;                //der head der Playlist wird über den pointer NULL gesetzt
    pl->count = 0;                  //der Mengenzeiger ist 0
}

void addSongToPlaylist(Playlist* pl, const char* artist, const char* title) //
{
    pl->head = InsertAtBack(pl->head, artist, title);   //insertatback gibt einen head zurück d.h. nimmt pl head den had wert an
    pl->count++;                                        //counter geht hoch, x songs sind i. d. Playlist
}

void printPlaylist(const Playlist* pl)                  //
{
    Song* temp = pl->head;
    while (temp) {
        printf("Artist: %s | Title: %s\n", temp->caartist, temp->catitle);
        temp = temp->pnext;
    }
}

void deleteFirst(Playlist* pl) //nur den playlistpointer brauch ich
{
    if (pl->head == NULL) return;       //falls der head direkt auf Null zeigt ist eh kein song mehr da

    Song* next = pl->head->pnext;       //merkt sich wert vom ersten pnext d.h. den zweiten song(auf den der zeigt)
    free(pl->head->caartist);           //freigeben vom artist des ersten Songs
    free(pl->head->catitle);            //freigeben vom titel des ersten songs
    free(pl->head);                     //dann wird gelöscht worauf der Head zeigt

    pl->head = next;                    //der head zeigt jetzt daruaf worauf der next zeigt, also dem ehemaligen zweiten song
    pl->count--;                        //Anzahl der Songs wird verringert
}

void deleteAll(Playlist* pl)            // alle songs löschen
{
    Song* temp = pl->head;              //remporärer pointer zeigt auf ersten Song
    while (temp) {                      // wärend der existiert
        Song* next = temp->pnext;       //next pointer zeigt auf zweiten song
        free(temp);                     //löschen von allem worauf der temp zeigt
        temp = next;
    }
    pl->head = NULL;                    //der Kopf ist dann Null
    pl->count = 0;                      // der Song-Counter ist 0
}



int main()
{
    Playlist pl;
    initPlaylist(&pl);

    char choice[10];
    char buff[100];

    while (1)
    {
        printf("Neuen Song erstellen? (ja/nein): ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0';

        if (strcmp(choice, "nein") == 0)
            break;

        if (strcmp(choice, "ja") != 0) {
            printf("Bitte 'ja' oder 'nein' eingeben.\n");
            continue;
        }

        printf("Artist Name: ");                        //Aufforderung zur Eingabe
        fgets(buff, sizeof(buff), stdin);               //
        buff[strcspn(buff, "\n")] = '\0';
        char artist[100];
        strcpy(artist, buff);

        printf("Song Title: ");
        fgets(buff, sizeof(buff), stdin);
        buff[strcspn(buff, "\n")] = '\0';
        char title[100];
        strcpy(title, buff);

        addSongToPlaylist(&pl, artist, title);
    }

    printf("\n--- Playlist ---\n");
    printPlaylist(&pl);

    printf("\nErsten Song löschen...\n");
    deleteFirst(&pl);

    printf("\n--- Playlist nach Löschen des ersten Songs ---\n");
    printPlaylist(&pl);

    printf("\nKomplette Playlist löschen...\n");
    deleteAll(&pl);

    return 0;
}
