#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

int SaisieEtoileChampion;
int SaisieLevelChampion;

int XPChampion;
int XPCumuleChampion;
int XPTotalChampion;
int XPMaxChampion;
int XPManquantChampion;

int EnergieAraignee20;
int EnergieDragon20;
int EnergieCampagne12_6;

int i;

int Dragon20 = 5782 ;
int NRoundDragon20;

int Araignee20 = 5800;
int NRoundAraignee20;

int CampagneBrutale12_6= 8800;
int NRoundCampagneBrutale12_6;

int NombreRound ;

/* **** Debut de tableau tableau afin connaitre le nombre XP par level **** */

int ChampionEtoilesXP [6][59] = 
{
    {897,1118,1393,1736,2163,2695,3359,4185,5215},
    {1110,1258,1426,1616,1831,2075,2351,2664,3019,3421,3876,4392,4977,5640,6390,7241,8205,9298,10536},
    {1279,1411,1556,1717,1893,2088,2303,2541,2802,3091,3409,3760,4147,4574,5045,5565,6138,6769,7466,8235,9083,10018,11050,12188,13442,14827,16353,18037,19894 },
    {1460,1591,1734,1890,2060,2245,2447,2666,2906,3167,3451,3761,4099,4467,4868,5305,5782,6301,6867,7483,8155,8888,9686,10556,11504,12537,13663,14890,16227,17684,19272,21003,22889,24945,27185,29627,32287,35187,38347,},
    {1625,1760,1907,2066,2238,2424,2626,2845,3082,3338,3616,3918,4244,4597,4980,5395,5844,6331,6858,7430,8048,8719,9445,10231,11084,12007,13007,14090,15264,16535,17912,19404,21020,22770,24667,26721,28947,31358,33970,36799,39864,43184,46780,50677,54897,59470,64423,69788,75601},
    {1813,1956,2110,2277,2457,2651,2860,3086,3329,3592,3876,4182,4512,4869,5253,5668,6115,6598,7119,7681,8288,8942,9648,10410,11232,12119,13076,14109,15223,16425,17722,19121,20631,22260,24018,25914,27961,30168,32551,35121,37894,40886,44115,47598,51357,55412,59787,64508,69602,75098,81028,87426,94329,101778,109815,118486,127842,137937,148828}
};
/* **** Fin de tableau tableau **** */


/* *** Fonction question *** */
long Question()
{
    printf("\n\t Entrez le nombre d'étoile du champion: ");
    scanf ("%i",&SaisieEtoileChampion);
    // printf("\t Nombre d'étoile du champion: %i",SaisieEtoileChampion);

    printf("\n\t Entrez le level du champion: ");
    scanf ("%i",&SaisieLevelChampion);
    // printf("\t Level du champion: %i",SaisieLevelChampion);

    switch (SaisieEtoileChampion)
        {
        case 1 : XPMaxChampion = 22761; break;
        case 2 : XPMaxChampion = 81326; break;
        case 3 : XPMaxChampion = 200681; break;
        case 4 : XPMaxChampion = 449082; break;
        case 5 : XPMaxChampion = 963806; break;
        case 6 : XPMaxChampion = 2010869; break;     
        default : { printf("\n\n\t  ****** Erreur de saisie. *****"); return 0;} 
        }   
    XPChampion = ChampionEtoilesXP[(SaisieEtoileChampion -1)][(SaisieLevelChampion -1)];
    printf("\n\t XP du (%i étoiles) au (Level %i) : %i\n",SaisieEtoileChampion, SaisieLevelChampion,XPChampion);
        //printf ("\n\t*** Fin Question () **** *************************************************************\n");
return 0;
}

long CalculXPmanquant ()
{
for (i = 0; i < SaisieLevelChampion ; i++)
    {
        XPCumuleChampion = XPCumuleChampion + ChampionEtoilesXP[(SaisieEtoileChampion -1)][i];
        // printf("\n\t XPTotalChampion en cours: %i, level %i, ajout de %i XP.", XPTotalChampion, i ,(ChampionEtoilesXP[SaisieEtoileChampion][i]));
    }
//printf("\n\t **** XP cumulés du Champion: %i\n", XPCumuleChampion);
}

long Reponse()
{
    printf (" \n\t\t\t\t\t *** Récapitulatif ***.");
   // XPChampion = ChampionEtoilesXP[(SaisieEtoileChampion -1)][(SaisieLevelChampion -1)];
    //printf("\n\tNombre total d XP: %i\n",XPTotalChampion);

    XPManquantChampion =XPMaxChampion -XPCumuleChampion;
        
    NRoundAraignee20= (XPMaxChampion - XPCumuleChampion) / Araignee20;    //NombreRound = 
        EnergieAraignee20= NRoundAraignee20 * 16;
    NRoundDragon20= (XPMaxChampion - XPCumuleChampion) / Dragon20;
        EnergieDragon20 = NRoundDragon20 *16;
    NRoundCampagneBrutale12_6  = (XPMaxChampion - XPChampion) / CampagneBrutale12_6;
        EnergieCampagne12_6 = NRoundCampagneBrutale12_6 *8;

    printf("\n\t*** %i *** XP cumulés du Champion.\n", XPCumuleChampion);
    //printf("\n\tXP du (%i étoiles) au (Level %i) : %i\n",SaisieEtoileChampion, SaisieLevelChampion,XPChampion);
    printf("\n\tXP Maximum du %i étoiles : %i\n",SaisieEtoileChampion,XPMaxChampion);
    printf("\n\tXP manquant du champion (%i étoiles) : %i\n",SaisieEtoileChampion,XPManquantChampion);    
    //printf (" \n\t\t\t\t\t **** Fin Reponse ***.\n\n");
    return 0;
}


int ResultatFarm ()
{
    printf (" \n\t\t\t\t\t **** Resultat Farm ***.\n");
    // printf("\n\tXP Araignee-20 : %i\n",Araignee20);
    printf("\n\tNécéssite %i d'Energie pour faire %i rounds Araignee-20 (%i XP).\n",EnergieAraignee20, NRoundAraignee20,Araignee20);   
    printf("\n\tNécéssite %i d'Energie pour faire %i rounds Dragon-20 (%i XP).\n",EnergieDragon20 ,NRoundDragon20, Dragon20 );
    printf("\n\tNécéssite %i d'Energie pour faire %i rounds en Campagne brutale 12-6 (%i XP).\n",EnergieCampagne12_6,NRoundCampagneBrutale12_6 ,CampagneBrutale12_6);
    //printf (" \n\t\t\t\t\t **** Fin Farm ***.\n\n");
}

/*** Fonction main() ************************************************************************************************* */
int main()
{
Question ();
CalculXPmanquant ();
Reponse ();
ResultatFarm ();
printf("\n *** Fin du programme, merci. ***\n\n\n");
return 0;
exit(0);
}