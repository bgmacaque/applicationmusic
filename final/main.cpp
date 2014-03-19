/*


  TODO :

   PLACE : ASSOCIE UN NUMERO DE PLACE AVEC UNE NOTE

   Faire une classe tablature qui fait correspondre les notes d'une partition
   à la position sur la guitare
   Faire une classe corde qui gère les notes jouables sur une corde de la guitare
   (de la plus petite à la plus grande note, liste de notes)
   Faire un algo qui prends un accord en entrée et donne l'accord sous forme de position de note
   Il regardera sur quelle corde l'accord est jouable
   Elle associe donc la note à la position
   Faire une classe gamme (liste de plusieurs note) et faire des attributs statiques
   correspondant à des gammes connues
   Faire une classe solo permettant de générer un solo aléatoirement en fonction de la gamme
   Faire le JSON qui fonctionne
   Faire la lecture d'une partition.
   On prends un petit son qu'on lit en boucle jusqu'à ce que la durée est finie
   ça devrait marcher
   Tester la connexion de la base de données en locale

*/
//#include <iostream>
//#include "note.h"
//#include <vector>
//#include "partition.h"
//#include "chord.h"
//#include "analyze.h"
//#include "fmodinit.h"
//using namespace std;

//int main(int argc, char **argv)
//{

////    FModInit *fmodlib = new FModInit();
////    Analyze *a = new Analyze(fmodlib->getSystem(), fmodlib->getSound());
////    Note *n = new Note("A4", 440.0);
////    float diff;
////    a->start();

////    while(true){
////        a->mainNote(n, &diff);
////        usleep(1000);
////    }
////    a->close();
////    delete a;
////    delete fmodlib;
////    delete n;



//    Note *n1 = new Note("A4", 440.0);
//    Note *n2 = new Note("A5", 880.0);
//    Note *n3 = new Note("A6", 1760.0);
//    Note *n4 = new Note("A4", 440.0);

//    Partition *p = new Partition(120, 0.025, 0.025);
//    FModInit *fmodlib = new FModInit();
//    Analyze *a = new Analyze(fmodlib->getSystem(), fmodlib->getSound());
//    bool tune = true;
//    p->record(a, &tune);
//    delete p;
//    delete a;
////    delete fmodlib;
//    delete n1;
//    delete n2;
//    delete n3;
//    delete n4;

////    Partition *p = new Partition(120);
////    FModInit *fmodlib = new FModInit();
////    Analyze *a = new Analyze(fmodlib->getSystem(), fmodlib->getSound());

////    bool tune = true;
////    p->record(a, &tune);

////    delete a;
////    delete fmodlib;
////    delete p;
//    return 0;
//}
