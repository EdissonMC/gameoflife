// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header!

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
#include "lifegui.h"
#include "grid.h"

// Feel free to add any other #includes you might need here
using namespace std;


/*
    ESTE PROYECTO PERMITE EMULAR EL JUEGO DE LA VIDA O GAME OF LIFE
    PARA PROBARLO PODEMOS UTILIZAR EL grid PARA CARGAR EL PATRON INICIAL
*/

//  CHECK CheckVecinos PASANDOLE UNA COORDENADA --------------------------------------------------------------------------------------
    int checkVecinos(Grid<int>& myGrid, int myRow, int myCol ) {

    //    int rowTmp=0;
    //    int colTmp=0;

        int conteoCelulas=0;
        int row1 = myRow-1;
        int col1 = myCol-1;

        //  For 1
            for (int i = 1 ;i <= 9; i++) {
//                 std::cout << "\n["<< myRow <<"]" << "["<< myCol <<"]" <<"\n";
//                std::cout << "\n["<< row1 <<"]" << "["<< col1 <<"]" <<"\n";

                if(myGrid.inBounds(row1,col1)  ) {
                  //  std::cout  << "si existe, esta dentro de los limites \n";

                    if(myGrid[row1][col1] ==1 ){



                         if(row1 != myRow  || col1 != myCol) {
                             // std::cout<<"si tiene celula\n";

                               conteoCelulas++;
                         }
//                         else {
//                            std::cout<<"-box central con celula-\n";
//                          }
                    }
//                    else{
                        // std::cout<<"vacio\n";

//                         if(row1 == myRow  && col1 == myCol) {
//                              std::cout<<"- box central vacia -\n";
//                         }
//                    }

                 }
//                else{
//                    std::cout<<"no existe\n";
//                 }

                 // std::cout<<i<<"\n";
                if(i%3==0){
                    //std::cout<<"----saltando--------------- \n";
                    row1 = row1 + 1;
                    col1 = myCol - 1;

                }else{
                    col1++;
                }

            }
        //  End for 1

            std::cout << "NUMERO DE CELULAS ALREDEDOR =" << conteoCelulas << "\n";


            return conteoCelulas ;
    }
//  END CheckVecinos() --------------------------------------------------------------------------------------






//  SHOWGRID --------------------------------------------------------------------------------------
    void showGrid( Grid<int>& myGrid){

        //std::cout << myGrid.toString();
        //for (int i= 0 ;i <10; i++){

           Grid<int> myGridTemp  = {
               {0,0,0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0,0,0}
            };

        //  For1
            for (int row = 0 ;row <myGrid.numRows(); row++) {
                // For2
                for (int col = 0 ;col <myGrid.numCols(); col++) {
                    //if(myGrid[row][col] == 1)

                    std::cout <<"[" << row << " , " << col <<"] ";
                    if (checkVecinos (myGrid,row,col) <= 1){
//                        std::cout << "estoy en conteoCelulas <= 1 \n";
                            LifeGUI::fillCell(row, col, 0);
                            myGridTemp[row][col] = 0;

                    }else if (checkVecinos (myGrid,row,col) == 2){

//                          std::cout << "estoy en conteoCelulas= 2 \n";
                       // if(myGrid[row][col] == 1){
                             LifeGUI::fillCell(row, col, myGrid[row][col]);
                             myGridTemp[row][col] = myGrid[row][col];
                        //}

                    }else if (checkVecinos (myGrid,row,col) == 3){
//                          std::cout << "estoy en conteoCelulas= 3 \n";
                            LifeGUI::fillCell(row, col, 1);
                            myGridTemp[row][col] = 1;
                    }else if (checkVecinos (myGrid,row,col) > 4){
//                         std::cout << "estoy en conteoCelulas > 4 \n";
                            LifeGUI::fillCell(row, col, 0);
                            myGridTemp[row][col] = 0;
                    }


                } // End for2
            }// End for1


            myGrid = myGridTemp;
            std::cout <<"\n" << myGridTemp << "\n";
            LifeGUI::repaint();

            pause(700);
            LifeGUI::clear();
        //}
    }
//  END  SHOWGRID --------------------------------------------------------------------------------------







    //  SHOWGRID --------------------------------------------------------------------------------------
        void showGridSimple( Grid<int>& myGrid){

            //std::cout << myGrid.toString();
            //for (int i= 0 ;i <10; i++){

               Grid<int> myGridTemp  = {
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0}
                };

            //  For1
                for (int row = 0 ;row <myGrid.numRows(); row++) {
                    // For2
                    for (int col = 0 ;col <myGrid.numCols(); col++) {
                       if(myGrid[row][col] == 1){
                             LifeGUI::fillCell(row, col,1);
                       }


                    } // End for2
                }// End for1



                LifeGUI::repaint();

                pause(300);
                LifeGUI::clear();
            //}
        }
    //  END  SHOWGRID --------------------------------------------------------------------------------------






//  MAIN-PRINCIPAL --------------------------------------------------------------------------------------
    int main() {
        // TODO: Finish the program!


//        Grid<int> myGrid = {
//           {0,0,0,0,0},
//           {0,0,0,0,0},
//           {0,0,0,0,0},
//           {0,0,0,0,0},
//           {0,0,0,0,0}
//        };


        /*Glider spaceship*/
//        Grid<int> myGrid = {
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,1,0,0,0,0,0,0,0},
//           {0,0,1,1,0,0,0,0,0,0},
//           {0,1,0,1,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0}
//        };


        /*Light Weight Space ship*/
        Grid<int> myGrid = {
           {0,0,0,0,0,0,0,0,0,0},
           {0,0,0,1,1,1,0,0,0,0},
           {0,0,1,0,0,1,0,0,0,0},
           {0,0,0,0,0,1,0,0,0,0},
           {0,0,0,0,0,1,0,0,0,0},
           {0,0,1,0,1,0,0,0,0,0},
           {0,0,0,0,0,0,0,0,0,0},
           {0,0,0,0,0,0,0,0,0,0},
           {0,0,0,0,0,0,0,0,0,0},
           {0,0,0,0,0,0,0,0,0,0}
        };

        /*Oscillate Blinker*/
//        Grid<int> myGrid = {
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,1,0,0,0,0,0,0,0},
//           {0,0,1,0,0,0,0,0,0,0},
//           {0,0,1,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0}
//        };

        /*Oscillate Toad */
//        Grid<int> myGrid = {
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,1,0,0,0,0,0,0,0},
//           {1,0,0,1,0,0,0,0,0,0},
//           {1,0,0,1,0,0,0,0,0,0},
//           {0,1,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0},
//           {0,0,0,0,0,0,0,0,0,0}
//        };



//         std::cout<<myGrid.toString();

        std::cout<<  checkVecinos(myGrid, 4,0)<< "\n";

        LifeGUI::initialize();
        LifeGUI::resize(10, 10);
        showGridSimple(myGrid);


//        pause(200);
//        LifeGUI::clear();
//        showGrid(myGrid);

//        pause(200);
//        LifeGUI::clear();
//        showGrid(myGrid);

//        pause(200);
//        LifeGUI::clear();
//        showGrid(myGrid);

//        pause(200);
//        LifeGUI::clear();
//        showGrid(myGrid);

//        pause(200);
//        LifeGUI::clear();
//        showGrid(myGrid);

        std::cout <<"> ";
        std::string keycontrol="";
       while (getline(std::cin, keycontrol)){
            if (keycontrol=="j"){
                std::cout <<"Presionada\n";
                  showGrid(myGrid);
            }
             std::cout <<"> ";
       }



//        for (int i = 0 ;i < 30; i++) {
//             showGrid(myGrid);


//        }

        //              std::cout <<myGrid.toString() << "\n\n";
        //               std::cout<< "\nGRID"<<"\n";


    //    myGrid[0][0]= 0;
    //    myGrid[1][1]= 1;
    //    myGrid[2][2]= 1;
    //    myGrid[3][3]= 1;
    //    myGrid[4][4]= 1;

    //     showGrid(myGrid);


    //     myGrid[0][0]= 0;
    //     myGrid[1][1]= 0;
    //     myGrid[2][2]= 0;
    //     myGrid[3][3]= 1;
    //     myGrid[4][4]= 1;

    //      showGrid(myGrid);



    //      myGrid[0][0]= 0;
    //      myGrid[1][1]= 0;
    //      myGrid[2][2]= 1;
    //      myGrid[3][3]= 1;
    //      myGrid[4][4]= 1;

    //       showGrid(myGrid);


    //       myGrid[0][0]= 0;
    //       myGrid[1][1]= 1;
    //       myGrid[2][2]= 1;
    //       myGrid[3][3]= 1;
    //       myGrid[4][4]= 1;

    //        showGrid(myGrid);


    //        myGrid[0][0]= 1;
    //        myGrid[1][1]= 1;
    //        myGrid[2][2]= 1;
    //        myGrid[3][3]= 1;
    //        myGrid[4][4]= 1;

    //         showGrid(myGrid);


    //    LifeGUI::fillCell(3, 4, 1);
    //    LifeGUI::repaint();

        return 0;
    }
//  END MAIN --------------------------------------------------------------------------------------






















    /*

// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header!

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
#include "lifegui.h"
#include "grid.h"

// Feel free to add any other #includes you might need here
using namespace std;




//  CHECK CheckVecinos PASANDOLE UNA COORDENADA --------------------------------------------------------------------------------------
    int checkVecinos(Grid<int>& myGrid, int myRow, int myCol ) {

    //    int rowTmp=0;
    //    int colTmp=0;

        int conteoCelulas=0;
        int row1 = myRow-1;
        int col1 = myCol-1;

        //  For 1
            for (int i = 1 ;i <= 9; i++) {

                std::cout << "\n["<< row1 <<"]" << "["<< col1 <<"]" <<"\n";

                if(myGrid.inBounds(row1,col1)) {
                    std::cout  << "si existe, esta dentro de los limites \n";

                    if(myGrid[row1][col1]==1 ){
                        conteoCelulas++;
                        std::cout<<"si tiene celula\n";

                         if(row1==myRow  && col1 == myCol) {
                              std::cout<<"-box central con celula-\n";
                         }
                    }else{
                         std::cout<<"vacio\n";

                         if(row1 == myRow  && col1 == myCol) {
                              std::cout<<"- box central vacia -\n";
                         }
                    }

                 }else{
                    std::cout<<"no existe\n";
                 }

                  std::cout<<i<<"\n";
                if(i%3==0){
                    std::cout<<"----saltando--------------- \n";
                    row1 = row1 + 1;
                    col1 = myCol-1;

                }else{
                    col1++;
                }

            }
        //  End for 1

            std::cout << "NUMERO DE CELULAS ALREDEDOR =" << conteoCelulas << "\n";

            if (conteoCelulas <= 1){
                std::cout << "estoy en conteoCelulas <= 1 \n";
                return -1;
            }else if (conteoCelulas == 2){
                  std::cout << "estoy en conteoCelulas= 2 \n";
                  return 0;
            }else if (conteoCelulas == 3){
                  std::cout << "estoy en conteoCelulas= 3 \n";
                  return 1;
            }else if (conteoCelulas > 4){
                 std::cout << "estoy en conteoCelulas > 4 \n";
                 return -1;
            }

            return 0;
    }
//  END CheckVecinos() --------------------------------------------------------------------------------------






//  SHOWGRID --------------------------------------------------------------------------------------
    void showGrid( Grid<int>& myGrid){
       std::cout << myGrid.toString();
        //for (int i= 0 ;i <10; i++){

           Grid<int> myGridTemp = {
              {0,0,0,0,0},
              {0,0,0,0,0},
              {0,0,0,0,0},
              {0,0,0,0,0},
              {0,0,0,0,0}
           };

            for (int row = 0 ;row <myGrid.numRows(); row++){
                for (int col = 0 ;col <myGrid.numCols(); col++){
                    if(myGrid[row][col] == 1)
                    {
                        LifeGUI::fillCell(row, col, 1);
                    }

                }
            }



            LifeGUI::repaint();

            pause(200);
            LifeGUI::clear();
        //}
    }
//  END  SHOWGRID --------------------------------------------------------------------------------------







//  MAIN-PRINCIPAL --------------------------------------------------------------------------------------
    int main() {
        // TODO: Finish the program!


        Grid<int> myGrid = {
           {0,0,0,0,0},
           {0,0,0,0,0},
           {0,0,0,0,0},
           {0,0,0,0,0},
           {0,0,0,0,0}
        };


        myGrid[0][0] = 1;
        myGrid[0][1] = 1;
        myGrid[0][4] = 1;
        myGrid[3][0] = 1;
        myGrid[3][1] = 1;
        myGrid[3][4] = 1;
        myGrid[4][1] = 1;
        myGrid[4][4] = 1;


         std::cout<<myGrid.toString();

          checkVecinos(myGrid, 3, 3);



//        LifeGUI::initialize();
//        LifeGUI::resize(5, 5);
//        showGrid(myGrid);


    //    myGrid[0][0]= 0;
    //    myGrid[1][1]= 1;
    //    myGrid[2][2]= 1;
    //    myGrid[3][3]= 1;
    //    myGrid[4][4]= 1;

    //     showGrid(myGrid);


    //     myGrid[0][0]= 0;
    //     myGrid[1][1]= 0;
    //     myGrid[2][2]= 0;
    //     myGrid[3][3]= 1;
    //     myGrid[4][4]= 1;

    //      showGrid(myGrid);



    //      myGrid[0][0]= 0;
    //      myGrid[1][1]= 0;
    //      myGrid[2][2]= 1;
    //      myGrid[3][3]= 1;
    //      myGrid[4][4]= 1;

    //       showGrid(myGrid);


    //       myGrid[0][0]= 0;
    //       myGrid[1][1]= 1;
    //       myGrid[2][2]= 1;
    //       myGrid[3][3]= 1;
    //       myGrid[4][4]= 1;

    //        showGrid(myGrid);


    //        myGrid[0][0]= 1;
    //        myGrid[1][1]= 1;
    //        myGrid[2][2]= 1;
    //        myGrid[3][3]= 1;
    //        myGrid[4][4]= 1;

    //         showGrid(myGrid);


    //    LifeGUI::fillCell(3, 4, 1);
    //    LifeGUI::repaint();

        return 0;
    }
//  END MAIN --------------------------------------------------------------------------------------

*/
