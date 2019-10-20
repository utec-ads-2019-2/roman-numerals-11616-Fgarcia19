#include <iostream>
#include <map>
using namespace std;

void roman(int numero){

    int unidades, decenas, centenas, millares;

    unidades = numero % 10; numero /= 10;
    decenas = numero % 10; numero /= 10;
    centenas = numero % 10; numero /= 10;
    millares = numero % 10; numero /= 10;

    switch (millares)
    {
        case 1: cout<<"M"; break;
        case 2: cout<<"MM"; break;
        case 3: cout<<"MMM"; break;
    }

    switch (centenas)
    {
        case 1: cout<<"C"; break;
        case 2: cout<<"CC"; break;
        case 3: cout<<"CCC"; break;
        case 4: cout<<"CD"; break;
        case 5: cout<<"D"; break;
        case 6: cout<<"DC"; break;
        case 7: cout<<"DCC"; break;
        case 8: cout<<"DCCC"; break;
        case 9: cout<<"CM"; break;
    }

    switch (decenas)
    {
        case 1: cout<<"X"; break;
        case 2: cout<<"XX"; break;
        case 3: cout<<"XXX"; break;
        case 4: cout<<"XL"; break;
        case 5: cout<<"L"; break;
        case 6: cout<<"LX"; break;
        case 7: cout<<"LXX"; break;
        case 8: cout<<"LXXX"; break;
        case 9: cout<<"XC"; break;
    }

    switch (unidades)
    {
        case 1: cout<<"I"; break;
        case 2: cout<<"II"; break;
        case 3: cout<<"III"; break;
        case 4: cout<<"IV"; break;
        case 5: cout<<"V"; break;
        case 6: cout<<"VI"; break;
        case 7: cout<<"VII"; break;
        case 8: cout<<"VIII"; break;
        case 9: cout<<"IX"; break;
    }
    cout<<endl;
}

void num(string roman){
    int numero=0;
    for(int i=0;i<roman.size();i++){
        switch (roman[i]){
            case 'I':
                if(roman[i+1]=='V'){
                    numero+=4;
                    i++;
                }
                else if(roman[i+1]=='X'){
                    numero+=9;
                    i++;
                }
                else
                {
                    numero++;
                }
                break;
            case 'V':
                numero+=5;

                break;
            case 'X':
                if(roman[i+1]=='L'){
                    numero+=40;
                    i++;
                }
                else if(roman[i+1]=='C'){
                    numero+=90;
                    i++;

                }
                else
                {
                    numero+=10;
                }
                break;
            case 'L':
                numero+=50;
                break;
            case 'C':
                if(roman[i+1]=='D'){
                    numero+=400;
                    i++;
                }
                else if(roman[i+1]=='M'){
                    numero+=900;
                    i++;

                }
                else
                {
                    numero+=100;
                }
                break;
            case 'D':
                numero+=500;
                break;
            case 'M':
                numero+=1000;
                break;
        }
    }
    cout<<numero<<endl;

}




int main() {
    string entrada;
    while(cin>>entrada) {
        if (isdigit(entrada[0]))
            roman(stoi(entrada));
        else
            num(entrada);
    }
    return 0;
}