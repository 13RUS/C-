#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;

    int w = 25, h = 25;

    for (int x=0; x < w; x++){
        for (int y=0; y < h; y++) {

            // 01
            if (x<y) std::cout << "# ";

            //02
            //if ((x==y) std::cout << "# ";

            //03
            // if ((w-x-1)==y) std::cout << "# ";

            //04
            //if (w-x+5>y) std::cout << "# ";

            //05
            //if ((y==x*2)||(y==x*2+1)) std::cout << "# ";

            //06
            //if (((x > 10) && (y < 10)) || (x < 11)) std::cout << "# ";

            //07
            //if (x>15 && y>15) std::cout << "# ";

            //08
            //if (x*y == 0) std::cout << "# ";

            //09
            //if ((y>x+10) || (y<x-10)) std::cout << "# ";

            //10
            //if ((y>=x+1) && (y<=x+x+1)) std::cout << "# ";

            //14
            //if (x*y < 105) std::cout << "# ";

            //18
            //if ( (x<2 && y!=0 || y <2 && x!=0) ) std::cout << "# ";

            //19
            //if ((x == 0) || (y==0) || (x==w-1) || (y==h-1)) std::cout << "# ";

            //20
            //if ((x+y) % 2 == 0) std::cout << "# ";

            //21
            //if (y%(x+1) < 1) std::cout << "# ";

            //22
            //if ((x+y) % 3 ==0 ) std::cout << "# ";

            //23
            //if (x%3==0 && y%2==0) std::cout << "# ";

            //24
            //if (x==y || x==w-y-1) std::cout << "# ";

            //25
            //if (x%6==0 || y%6==0) std::cout << "# ";

            else std::cout << ". ";
        }
        std::cout << std::endl; //1 5 9 13 17
    }

    return 0;
}
