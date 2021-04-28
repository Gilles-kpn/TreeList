#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef void Object;
typedef struct Noeud* PNoeud;
typedef struct Noeud
{
    Object* valeur;
    PNoeud filsGauche;
    PNoeud filsDroit;
}Arbre;

typedef struct Cellule* PCellule;
typedef struct Cellule
{
    PNoeud value;
    PCellule next;
}List;

typedef struct {
    List *tete;
    List *que;
}LFile;

int estFileVide(LFile* fl){
    if (fl->tete != NULL && fl->que == NULL)
    {
       return 0;
    }else{
        return 1;
    }
    
}

void enfiler(LFile* fl,PNoeud noeud){
    PCellule nouveau = malloc(sizeof(PCellule));
    nouveau->value = noeud;
    nouveau->next = NULL;
    if (estFileVide(fl) != 1){
        fl->que->next = nouveau;
    }else{
        fl->tete = nouveau;
    }
    
}

PNoeud defiler(LFile* fl){
    PNoeud noeud = NULL;
    if (estFileVide(fl)!=1)
    {
        noeud = fl->tete->value;
        fl->tete = fl->tete->next;
    }
    if (fl->tete == NULL)
    {
        fl->que = NULL;
    }
    return noeud;
    
}

PNoeud creationNoeud(Object* ob,PNoeud filsgauche,PNoeud filsdroit){
    PNoeud nouveau = malloc(sizeof(PNoeud));
    nouveau->valeur = ob;
    nouveau->filsDroit = filsdroit;
    nouveau->filsGauche = filsgauche;
    return nouveau;
}

Object* renvoyerNoeud(PNoeud noeud){
    return noeud->valeur;
}

PNoeud creationFeuille(Object * obj)
{
    return creationNoeud(obj,NULL,NULL);
}


int main(int argc, char const *argv[])
{
    
    
    return 0;
}
