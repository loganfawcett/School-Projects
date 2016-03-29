/* Rachel's Menu Object. Since these are static functions, you won't create a Menu object */
/* Call things like: */
/* Menu::ShowMenu( options, 3 ); */

#ifndef _MENU
#define _MENU

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Menu
{
    public:
    // OUTPUT
    static void ClearScreen();
    static void Header( const string& header );
    static void DrawHorizontalBar( int width, char symbol = '-' );

    // MENUS and INPUT/OUTPUT
    static void ShowMenu( const vector<string> options, bool vertical = true );
    static int ShowMenuWithPrompt( const vector<string> options, bool vertical = true );

    static int GetValidChoice( int min, int max, const string& message = "" );
    static string GetValidStringChoice( const vector<string> options, bool caseSensitive = false );

    // UTILITIES
    static string IntToString( int num );
    static int StringToInt( const string& str );
    static string ToUpper( const string& val );
};

void Menu::DrawHorizontalBar( int width, char symbol )
{
    for ( int i = 0; i < width; i++ )
    {
        cout << symbol;
    }
    cout << endl;
}

void Menu::Header( const string& header )
{
    DrawHorizontalBar( 80 );
    string head = "| " + header + " |";
    cout << " " << head << endl << " ";
    DrawHorizontalBar( head.size() );
    cout << endl;
}

void Menu::ShowMenu( const vector<string> options, bool vertical )
{
    if ( vertical )
    {
        for ( unsigned int i = 0; i < options.size(); i++ )
        {
            cout << " " << (i+1) << ".\t" << options[i] << endl;
        }
    }
    else
    {
        for ( unsigned int i = 0; i < options.size(); i++ )
        {
            cout << " " << (i+1) << ". " << options[i] << "\t";
        }
        cout << endl;
    }
}

int Menu::ShowMenuWithPrompt( const vector<string> options, bool vertical )
{
    ShowMenu( options, vertical );
    int choice = GetValidChoice( 1, options.size() );
    return choice;
}

int Menu::GetValidChoice( int min, int max, const string& message )
{
    if ( message != "" )
    {
        cout << endl;
        DrawHorizontalBar( message.size() + 2 );
        cout << " " << message << endl;
    }

    int choice;
    cout << " >> ";
    cin >> choice;

    while ( choice < min || choice > max )
    {
        cout << "Invalid selection. Try again." << endl;
        cout << ">> ";
        cin >> choice;
    }

    return choice;
}

string Menu::GetValidStringChoice( const vector<string> options, bool caseSensitive )
{
    cout << " Options: ";
    for ( int i = 0; i < options.size(); i++ )
    {
        cout << " [" << options[i] << "]";
    }

    string choice;
    cout << endl << " >> ";
    cin >> choice;

    while ( true )
    {
        for ( int i = 0; i < options.size(); i++ )
        {
            string option = options[i];
            if ( !caseSensitive )
            {
                choice = Menu::ToUpper( choice );
                option = Menu::ToUpper( option );
            }

            if ( choice == option )
            {
                return choice;
            }
        }

        cout << " Invalid input. Try again." << endl;
    }
}

void Menu::ClearScreen()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "cls" );
    #else
        system( "clear" );
    #endif
}

string Menu::IntToString( int num )
{
    return to_string( num );
}

int Menu::StringToInt( const string& str )
{
    return stoi( str );
}

string Menu::ToUpper( const string& val )
{
    string upper = "";
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        upper += toupper( val[i] );
    }
    return upper;
}

#endif

