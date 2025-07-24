#include <iostream>
#include <ctime>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

const int VAL_RIGHE = 5;
const int VAL_COLONNE = 5;
const int VAL_SPAZZI = 42;

char lettereColonna[VAL_RIGHE] = {'A', 'B', 'C', 'D', 'E'};


void stampaGrigliaCensurataDi(int grigliaBattagliaNemico[VAL_RIGHE][VAL_COLONNE])
{
    cout << '\t';

    for (int i = 0; i < VAL_RIGHE; i++)
    {
        cout << lettereColonna[i] << '\t';
    }

    cout << endl;

    for (int i = 0; i < VAL_RIGHE; i++)
    {
        cout << i + 1 << '\t';

        for (int j = 0; j < VAL_COLONNE; j++)
        {
            if (grigliaBattagliaNemico[i][j] == 0)
            {
                cout << "-" << '\t';
            }
            else if (grigliaBattagliaNemico[i][j] == 1)
            {
                cout << "X" << '\t';
            }
            else if(grigliaBattagliaNemico[i][j] == 3)
            {
                cout << "#" << '\t';
            }
            else
            {
                cout << "-" << '\t'; // altrimenti sarebbe una nave
            }
        }

        cout << endl;
    }

    cout << endl << endl;
}
void stampaGrigliaVisibileDi(int grigliaUtente[VAL_RIGHE][VAL_COLONNE])
{
    cout << '\t';

    for (int i = 0; i < VAL_RIGHE; i++)
    {
        cout << lettereColonna[i] << '\t';
    } // stampa le lettere sopra
    cout << endl;

    for (int i = 0; i < VAL_RIGHE; i++)
    {
        cout << i + 1 << '\t'; // il numero al inizio della griglia

        for (int j = 0; j < VAL_COLONNE; j++)
        {
            if (grigliaUtente[i][j] == 0)
            {
                cout << "-" << '\t';
            }
            else if (grigliaUtente[i][j] == 1)
            {
                cout << "X" << '\t';
            }
            else if(grigliaUtente[i][j] == 3)
            {
                cout << "#" << '\t';
            }else if(grigliaUtente[i][j] == 2)
            {
                cout << "@" << '\t';
            }
            else {
                cout << "-" << '\t'; // errore imprevisto che non ha senso (puo essere tolto questo ultimo else, ma per sicurezza no)
            }
        }

        cout << endl;
    }
    cout << endl << endl;
}

int inputValidation(int &input,int max) {

    while(cin.fail() || input > max) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"input non valido... ritenta"<<endl;
        cin>>input;
    }
    return input;
}

void piazzaNave(int griglia[VAL_RIGHE][VAL_COLONNE], int riga, char colonna)
{
    if (((riga >= 0) && (riga < VAL_RIGHE)) && (((colonna >= 0) && (colonna < VAL_COLONNE))))
    {
        if (griglia[riga][colonna] == 0)
        {
            griglia[riga][colonna] = 2;

            cout << "Nave piazzata con successo!" << endl;
            cout << endl;
        }
        else
        {
            cout << "C'è già una nave in questa posizione!" << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "Posizione non valida!" << endl;
        cout << endl;
    }
}

void MainMenu(string &choiceUser)
{
    cout << "Benvenuto in battaglia navale!" << endl;
    cout << endl << endl;

    cout << "1. Inizia nuova partita" << endl;
    cout << "2. Aiuto" << endl;
    cout << "3. Esci" << endl << endl;

    cout << "Scegli un'opzione: ";
    int scelta;
    cin >> scelta;

    inputValidation(scelta, 3); // Validazione dell'input

    choiceUser = to_string(scelta);
    cout << endl;

    cout << endl;
}
void HelpMenu(string &SceltaMenuHelp)
{
    cout << "2.1 Regole Battaglia Navale" << endl;
    cout << "2.2 Informazioni Griglia" << endl;
    cout << endl;

    cout << "Scegli un'opzione: ";
    cin >> SceltaMenuHelp;

    cout << endl;
}
void helpMenuOne()
{
    cout << "Regolamento Battaglia Navale:" << endl;
    cout << endl << endl;
    cout << "Basandoti sulla griglia 5x5 posiziona 5 navi in posizioni a tua scelta " << endl;
    cout << "Le Navi sono di grandezza 1x1 e hanno posizioni valide A-E 1-5" << endl;
    cout << "0 Simboleggia l'assenza di Navi, 1 la presenza" << endl;
    cout << "Il Campo avversario non e' visibile fino a fine battaglia" << endl;
    cout << "Vince chi riesce ad affondare tutte le navi nemiche per primo, occhio a non perdere!" << endl;
    cout << endl;
}
void helpMenutwo()
{
    cout << "Informazioni Griglia:" << endl;
    cout << endl << endl;
    cout << "- | Posizione Vuota ; Campo Utente / Punto Sconosciuto ; Campo Nemico" << endl;
    cout << "* | Posizione nave ; Campo Utente" << endl;
    cout << "X | Punto Colpito, Nave Affondata ; Entrambi i campi" << endl;
    cout << "# | Punto Colpito, Nessuna Nave presente ; Entrambi i campi" << endl;
    cout << endl;
}

void turnoNemico(int grigliaUtente[VAL_RIGHE][VAL_COLONNE]) {

    int riga, colonna;

    while (true) {

        riga = rand() % VAL_RIGHE;
        colonna = rand() % VAL_COLONNE;

        if (grigliaUtente[riga][colonna] == 0) {
            grigliaUtente[riga][colonna] = 3; // Colpo a vuoto

            cout << "Il computer ha colpito (" << riga + 1 << ", " << lettereColonna[colonna] << "): Colpo a vuoto!" << endl;
            break;
        } else if (grigliaUtente[riga][colonna] == 2) {

            grigliaUtente[riga][colonna] = 1; // Colpo a segno
            cout << "Il computer ha colpito ( " << riga + 1 << lettereColonna[colonna] << " ): Colpo a segno!" << endl<<endl;
            break;
        }
    }

    stampaGrigliaVisibileDi(grigliaUtente);
}

void gestisciPartita(int grigliaNemico[VAL_RIGHE][VAL_COLONNE], int grigliaUtente[VAL_RIGHE][VAL_COLONNE])
{
    int riga, colonna;
    string scelta;
    int ColpiASegno = 5;

    for(ColpiASegno; ColpiASegno >0; ColpiASegno--)
    {
        cout << "Scegli una posizione (riga, colonna) per il colpo. Ad esempio: 1A" << endl;
        cout << endl;

        cout << "Inserisci 'q' per uscire." << endl;
        cout << "Posizione: ";
        cout << endl;

        cin >> scelta;

        if (scelta == "q" || scelta == "Q")
        {
            cout << "Uscita dal gioco..." << endl;
            cout << endl;

            break;
        }

        if (scelta.length() == 2)
        {
            riga = scelta[0] - '1';
            colonna = toupper(scelta[1]) - 'A';
        }
        else if (scelta.length() == 3 && scelta[1] == ' ')
        {
            riga = scelta[0] - '1';
            colonna = toupper(scelta[2]) - 'A'; //conversione da carattere in numero
        }
        else
        {
            cout << "Input non valido!" << endl;
            cout << endl;

            continue;
        }

        if (riga >= 0 && riga < VAL_RIGHE && colonna >= 0 && colonna < VAL_COLONNE)
        {
            if (grigliaNemico[riga][colonna] == 2)
            {
                grigliaNemico[riga][colonna] = 1;

                cout << "Colpo a segno!" << endl;
            }
            else
            {
                grigliaNemico[riga][colonna] = 3;

                cout << "Colpo a vuoto!" << endl;

            }
        }

        cout<<"hai ancora "<<ColpiASegno<<" colpi rimasti"<<endl<<endl;
        stampaGrigliaCensurataDi(grigliaNemico);
        cout<<"--------------------------------------"<<endl;
        cout<<"Ora e il turno del Nemico a colpire : "<<endl<<endl;
        turnoNemico(grigliaUtente);

    }
}

bool piazzaNaveCasuale(int griglia[VAL_RIGHE][VAL_COLONNE], int naviDaPosizionare)
{
    for(int i=0; i<naviDaPosizionare; i++)
    {
        int riga = rand() % VAL_RIGHE;
        int colonna = rand() % VAL_COLONNE;

        if (griglia[riga][colonna] == 0)
        {
            griglia[riga][colonna] = 2;
        }
    }

    return true;
}

int main() {
    srand(time(NULL));

    int grigliaNemico[VAL_RIGHE][VAL_COLONNE] = {0};
    int grigliaUtente[VAL_RIGHE][VAL_COLONNE] = {0};

    piazzaNaveCasuale(grigliaNemico, 5);
    string SceltaUtente, SceltaMenuHelp;

    while (true) {
        MainMenu(SceltaUtente);
        if (SceltaUtente == "1")
        {
            stampaGrigliaVisibileDi(grigliaUtente);
            cout << "Posiziona le tue navi (usa il formato: numero della riga e lettera della colonna, ad esempio 1 A)." << endl;
            cout << "Piazza 5 navi." << endl;

            cout << endl;

            for (int i = 0; i < 5; i++)
            {

                int riga;
                char colonna;

                cout << "Posiziona la nave N." << i + 1 << " : ";
                cin >> riga;
                inputValidation(riga, 5);

                cin >> colonna;
                cout << endl;



                colonna = toupper(colonna);
                piazzaNave(grigliaUtente, riga - 1, colonna - 'A');
                stampaGrigliaVisibileDi(grigliaUtente);
            }

            //                                                       Inizio vero e proprio del gioco
            cout<<"Ok, ora iniziamo a colpire il nemico !\n";
            stampaGrigliaCensurataDi(grigliaNemico);//               campo censurato

            gestisciPartita(grigliaNemico, grigliaUtente);

        }

        else if(SceltaUtente == "2")
        { //                                     inizio menu help
            HelpMenu(SceltaMenuHelp);

            if (SceltaMenuHelp == "2.1")
            {
                helpMenuOne();
            }
            else if(SceltaMenuHelp == "2.2")
            {
                helpMenutwo();
            }
            else
            {
                cout << "Valore inserito non valido" << endl;
                cout << endl;
            }
        } //                      menu help
        else if (SceltaUtente == "3")
        {
            cout << "Torna a giocare quando vuoi!" << endl;
            cout << endl;

            break;
        } //                      fine prog
        else
        {
            cout << "Scelta non valida!" << endl;
            cout << endl;
        }
    }
    return 0;
}
 
