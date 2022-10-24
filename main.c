#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int nb_sommet;
int  tab[100][100]; //matrice d'adjacence
char M[100][100];
//********** graphe vide **********/
bool vide () {
 if(nb_sommet==0){
  return true;
   }else
   {
      return false;
    }
}
//********** graphe connex **********/
bool connexe(){
int i,j,x,w;
  if(!vide() )
  {
    for (i=0;i<nb_sommet;i++){
      for (j=0;j<nb_sommet;j++){
         if(tab[i][j]==0)
         {
             w=1;
         }
         else
            w=0;
         }
          if(w=1)
         {
             for (x=0;x<nb_sommet;x++){
                 if(tab[i][j]==0)
         {
             w=1;
         }
         else
            w=0;

             }
         }
         return true ;
    }

     return false ;
   }
      return false ;
}
//********** graphe diagonale **********/
bool diagonal(){
  int i,j ;
  if(!vide() )
  {
    for (i=0;i<nb_sommet ; i++){
      for (j=0;j<nb_sommet ; j++){
         if((i!=j && tab[i][j]==0 ) || tab[i][i]==1)
                return false  ;

         }
    }

     return true ;
   }
      return false ;
}
//********** graphe trivial **********/
bool trivial(){
  if(nb_sommet!=0)
  {
   int i,j;
    for (i=0;i<nb_sommet;i++)
     {
      for (j=0;j<nb_sommet;j++)
       {
        if(tab[i][j]==0)
       {return true ; }
       }
     }
       return false ;
 }
return false;
}
//********** graphe symetrique **********/
bool symetrique(){
int i,j ;
 if(!vide() ){
 for (i=0 ; i<nb_sommet ; i++) {
 	for (j=0 ; j<nb_sommet ; j++){
 		 if(i!=j && tab[i][j]!=tab[j][i])
 		 	return false ;
   return true ;
 	}
 }
}
return false ;
}
//********** graphe antisymetrique **********/
bool antisymetrique(){

  int i , j ;
 if(!vide() ){
 for (i=0;i<nb_sommet;i++)
    for (j=0;j<nb_sommet;j++)
        if(i!=j && tab[i][j]==tab[j][i]) return false ;
   return true ;
}
return false ;
}
//********** graphe reflexive **********/
bool reflexive(){
    int i ;

  if(!vide() && !trivial()){
   for (i=0 ; i<nb_sommet ; i++) {
    if(tab[i][i]==0)
     {return false ; }
      else {return true ;}
   }
   return false ;
  }
}
//********** graphe antireflexive **********/
bool antireflex(){
    int i ;

  if(!vide()) {

   for (i=0;i<nb_sommet;i++)
   if(tab[i][i]==1)
    return false  ;
     return true ;
  }
  return false ;
}

//********** graphe complet **********/
bool complet() {
  if(nb_sommet!=0){
  int i,j;
   for (i=0;i<nb_sommet;i++)
    for (j=0;j<nb_sommet;j++)
      if(tab[i][j]==0)
        return false ;
            return true ;}
   return false ;
}
//********** graphe simple **********/
bool simple (){
  int i ;
  if(!vide() && antisymetrique()) {
    for (i=0 ; i<nb_sommet ; i++)
        if( tab[i][i]==1)
           return false ;
             return true ;}
              return false ;
}




int main() {
  int i,j,k,l;
  char c;
// remplissage
 printf("\n-------------------- LES TYPES DE GRAPHE -------------------- \n\n\n");
 printf("  Donnez le nombre de sommets : \n");
 scanf("%d",&nb_sommet);
 printf("On utilise la matrice d'adjacence  , donnez les elemement de la matrices : \n");


 for(i=0;i<nb_sommet;i++){
     for(j=0;j<nb_sommet;j++){
        M[i][j]='-';
     }
     printf("\n");
  }



 for (i=0;i<nb_sommet;i++)
    {
   for (j=0;j<nb_sommet;j++)
     {

              for(k=0;k<nb_sommet;k++){
 	           printf("           ");
                for(l=0;l<nb_sommet;l++){
                 if(k==i && l==j){
                  printf("? ");}
                   else{
                     printf("%c ", M[k][l]);
                       }
                                        }
                      printf("\n");
                                       }
    scanf("%d",&tab[i][j]);
    c=tab[i][j] + '0';
    M[i][j]=c;
      }
     }


 printf("\n\n Ce graphe est :\n\n");
 if(connexe()==true){
 printf("         * connexe\n");}
  if(vide()==true){
 printf("         * vide\n");}
  if(trivial()==true){
 printf("         * trivial\n");}
  if(diagonal()==true){
 printf("         * Diagonal\n");}
  if(symetrique()==true){
 printf("         * symétrique\n");}
  if(antisymetrique()==true){
 printf("         * antisymétrique\n");}
  if(complet()==true){
 printf("         * complet\n");}
  if(simple()==true){
 printf("         * simple\n");}
if(reflexive()==true){
 printf("         * reflexif\n");}
  if(antireflex()==true){
 printf("         * antireflexif\n");}
  return 0;
}
