#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void Object;

typedef struct CelluleDbl * PCelluleDbl;
typedef struct CelluleDbl{
    Object* valeur;
    PCelluleDbl suivant;
    PCelluleDbl precedant;
}ListeDbl;
void creerListDbl(PCelluleDbl l , int n){
    PCelluleDbl tete = l,p;
    int donnee;
    printf("*********************Enregistrement de %d element \n",n);
    for (int i = 1; i <= n ; i++)
    {
        if (i==1)
        {
            printf("Entrer le premier element \t");
            scanf("%d",&donnee);
            tete->valeur = donnee;
            tete->suivant = NULL;
            tete->precedant = NULL;

        }else {
            p = malloc(sizeof(PCelluleDbl));
            printf("Entrer l'element suivant \t");
            scanf("%d", &donnee);
            p->valeur = donnee;
            p->precedant = tete;
            p->suivant = NULL;
            tete->suivant = p;
            tete=p;
        }
    }


}
void afficherListeDbl(PCelluleDbl l){
    PCelluleDbl p = l;
    int i = 1;
    printf("*************************Affichage de la liste\n");
    while(p != NULL){
        printf("Element  numero %d: %d \n",i, p->valeur);
        p = p->suivant;
        i++;
    }
}
void afficherListeInverseDbl(PCelluleDbl l){
    PCelluleDbl p = l;
    while (p->suivant != NULL)
    {
        p = p->suivant;
    }
    printf("*********************Affichage inverse de la Liste");
    while(p != NULL){
        printf(p->valeur);
        p  = p->precedant;
    }
}
PCelluleDbl ajouterTeteDbl(PCelluleDbl l){
    PCelluleDbl p ;
    p = malloc(sizeof(PCelluleDbl));
    printf("*********************Ajout en Tete \n");
    int donnee;
    printf("Entrer la valeur \t");
    scanf("%d",&donnee);
    p->valeur = donnee;
    p->suivant = l;
    p->precedant = NULL;
    return p;
}
void ajouterQueueDbl(PCelluleDbl l){
    PCelluleDbl p ;
    p = l;
    while(p->suivant != NULL){
        p = p->suivant;
    }
    printf("*********************Ajout en Queue \n");
    int donnee;
    printf("Entrer la valeur \t");
    scanf("%d",&donnee);
    PCelluleDbl que = malloc(sizeof(PCelluleDbl));
    que->valeur = donnee;
    que->precedant = p;
    que->suivant=NULL;
    p ->suivant = que;
    
}
void existDansListDbl(PCelluleDbl l){
    int donnee;
    printf("***********************Recherche de valeur\nEntrer la valeur a rechercher \t");
    scanf("%d",&donnee);
    int i = 1;
    bool find = false;
    while (l != NULL)
    {
        if(l->valeur == donnee){
            find = true;
            break;
        }
        l = l->suivant;
        i++;
    }
    if (find)
    {
        printf("Valeur trouvee a la position numero %d \n",i);
    }else{
        printf("Valeur non trouvee \n");
    }
}
bool rechercherDansListeDbl (PCelluleDbl l,int valeur , PCelluleDbl* precedant, PCelluleDbl * suivant){
    PCelluleDbl p  = l;
    while (p !=NULL)
    {
        if (p->valeur == valeur)
        {
            precedant = &p->precedant;
            suivant = &p->suivant;
            return true;
        }
        p = p->suivant;
    }
    return false;
}
PCelluleDbl supprimerDansListDbl(PCelluleDbl l){
    PCelluleDbl p ;
    printf("*************************Suppression dans la liste\n");
    int donnee;
    printf("Entrer la valeur a supprimer \t");
    scanf("%d",&donnee);
    if (l != NULL)
    {
      if (l->valeur == donnee)
      {
          p = l->suivant;
          p->precedant = NULL;
          free(l);
          return p;
      }else{
        p = l;
        p = p->suivant;
        while (p!= NULL)
        {
            if (p->valeur == donnee )
            {
                p->precedant->suivant = p->suivant;
                if (p->suivant == NULL)
                {
                   free(p);
                   return l;
                }else{
                    p->suivant->precedant = p->precedant;
                    free(p);
                    return l;
                }
                
            }
            
            p = p->suivant;
        } 
      }
    }
}
PCelluleDbl triabulle(PCelluleDbl l){
    PCelluleDbl p =l,q;
    printf("******************************Tri a Bulle\n");
    while (l!=NULL)
    {
        q= l->suivant;
        while (q!=NULL)
        {
            if (l->valeur > q->valeur)
            {
                int temp = l->valeur;
                l->valeur = q->valeur;
                q->valeur = temp;
            }

            q= q->suivant;
            
        }
        l = l->suivant;
    }
    return p;
}

int main(int args,char const *argv[]){
    PCelluleDbl celluledbl;
    celluledbl = malloc(sizeof(PCelluleDbl));
    int nombre ;
    printf("Entrer le nombre d'element dans cette liste \t");
    scanf("%d",&nombre);
    creerListDbl(celluledbl,nombre);
    afficherListeDbl(celluledbl);
    celluledbl = ajouterTeteDbl(celluledbl);
    afficherListeDbl(celluledbl);
    ajouterQueueDbl(celluledbl);
    afficherListeDbl(celluledbl);
    existDansListDbl(celluledbl);
    celluledbl =  supprimerDansListDbl(celluledbl);
    afficherListeDbl(celluledbl);
    celluledbl = triabulle(celluledbl);
    afficherListeDbl(celluledbl);
    
    return 0;
}


