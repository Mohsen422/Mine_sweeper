#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std ;
void game (int , int , int) ;
void win () ;
void gameover () ;
int main  ()
{
	int i , j , n ;
	cout << "MARK ALL MINES TO WIN " << endl << "." << endl << "." << endl ;
	cout << "ENTER NUMBEAR OF ROW  " << endl ;
	cin >> i ;
	cout << "ENTER NUMBER OF COLUMNS  "  << endl ;
	cin >> j ;
	cout << "ENTER NUMBER OF MINES  " << endl ;
	cin >> n ;
	game (i , j , n) ;
}
void game (int i , int j , int n)
{
	system("Color 02") ;
	int a , b , temp , o , p , sum = 0 ;
	int n_saver = n ;
	bool game = true ;
	char mtr [i+2][j+2] ;
	int mtr2 [i+2][j+2] ;
	int mtr3 [i+2][j+2] ;
	int mtr4 [i+2][j+2] ;
	for (int g = 0 ; g < i+2 ; g++)
	{
		for (int h = 0 ; h < j+2 ; h++)
		{
			mtr [g][h] = 254 ;
			mtr2 [g][h] = 0 ;
			mtr3 [g][h] = 0 ;
			mtr4 [g][h] = 0 ;
		}
	}
	cout << "j" << " " ;
	for (int g = 1 ; g <= j ; g++)
	{
		cout << g << "  " ;
	}
	cout << endl ;
	for (int g = 1  ; g < i + 1 ; g++)
	{
		cout << "  " ;
		for (int h = 1 ; h < j + 1 ; h++)
		{
			cout << mtr [g][h] << "  ";
		}
		cout << g << endl ;
	}
	for (int g = 0 ; g < j ; g++)
	{
		cout << "   " ;
	}
	cout << "  i" << endl ;
	cout << "i ? " ;
	cin >> a ;
	cout << "j ?" ;
	cin >> b ;
	while (n != 0)
	{
		o = rand() % i + 1 ;
		p = rand() % j + 1 ;
		if ((o == a) && (p == b) || (mtr2[o][p] == 1))
			continue ;
		mtr2 [o][p] = 1 ;
		n-- ;
	}
	temp =  mtr2 [a-1][b-1] + mtr2 [a][b-1] + mtr2 [a+1][b-1] + mtr2[a-1][b] + mtr2 [a+1][b] + mtr2 [a-1][b+1] + mtr2 [a][b+1] + mtr2 [a+1][b+1] + 48 ;
	mtr [a][b] = char (temp) ;
	mtr3 [a][b] = 1 ;
	cout << "j" << " " ;
	for (int g = 1 ; g <= j ; g++)
	{
		cout << g << "  " ;
	}
	cout << endl ;
	for (int g = 1  ; g < i + 1 ; g++)
	{
		cout << "  " ;
		for (int h = 1 ; h < j + 1 ; h++)
		{
			cout << mtr [g][h] << "  ";
		}
		cout << g << endl ;
	}
	for (int g = 0 ; g < j ; g++)
	{
		cout << "   " ;
	}
	cout << "  i" << endl ;
	while (game)
	{
		int c ;
		cout << "choose NULL press(1) || MARK A MINE press(2)  " ;
		cin >> c ;
		switch (c)
		{
			case (1) : 
			{
		cout << "i" ;
		cin >> a ;
		cout << "j" ;
		cin >> b ;
		mtr3 [a][b] = 1 ;
		if (mtr2 [a][b] == 1 )
		{
			cout << endl << "MINE :(" << endl ;
			for (int g = 1 ; g < i+1 ; g++ )
			{
				for (int h = 1 ; h < j+1 ; h++)
				{
					if (mtr2 [g][h] == 1 || mtr4 [g][h] == 1)
					{
						system("Color 04") ; 
						cout << char (42) << "  " ;
						system("Color 07") ;
					}
					else
					{
						system("Color 04") ;
						cout << char(248) << "  " ;
						system("Color 07") ;
					}
						system("Color 04") ;
				}
				cout << endl ;
			}
			exit (0) ;
		}
		for (int g = 1 ; g < i+1 ; g++)
		{
			for (int h = 1 ; h < j+1 ; h++)
			{
				sum = sum + mtr3 [g][h] ;
			}
		}
		if ( sum == i * j )
		{
			win () ;
		}
	temp =  mtr2 [a-1][b-1] + mtr2 [a][b-1] + mtr2 [a+1][b-1] + mtr2[a-1][b] + mtr2 [a+1][b] + mtr2 [a-1][b+1] + mtr2 [a][b+1] + mtr2 [a+1][b+1] + 48 ;
	mtr [a][b] = char (temp) ;
	cout << "j" << " " ;
				for (int g = 1 ; g <= j ; g++)
					{
						cout << g << "  " ;
					}
				cout << endl ;
				for (int g = 1  ; g < i + 1 ; g++)
					{
						cout << "  " ;
				for (int h = 1 ; h < j + 1 ; h++)
					{
				cout << mtr [g][h] << "  ";
					}
				cout << g << endl ;
			}
				for (int g = 0 ; g < j ; g++)
			{
				cout << "   " ;
			}
			cout << "  i" << endl ;
		break ;
			}
			case (2) :
			{
				cout << "i ? " ;
				cin >> a ;
				cout << "j ? " ;
				cin >> b ;
				if (mtr2 [a][b] == 1)
				{
					mtr [a][b] = char (251) ;
					mtr2 [a][b] = 0 ;
					mtr3 [a][b] = 1 ;
					mtr4 [a][b] = 1 ;
					sum = sum + 1 ;
				if ( sum == n_saver )
				{
				win () ;
				}
					cout << "j" << " " ;
				for (int g = 1 ; g <= j ; g++)
					{
						cout << g << "  " ;
					}
				cout << endl ;
				for (int g = 1  ; g < i + 1 ; g++)
					{
						cout << "  " ;
				for (int h = 1 ; h < j + 1 ; h++)
					{
				cout << mtr [g][h] << "  ";
					}
				cout << g << endl ;
			}
				for (int g = 0 ; g < j ; g++)
			{
				cout << "   " ;
			}
			cout << "  i" << endl ;
		}
				else 
				{
					gameover () ;	
				}
				break ;
			}
			default :
				{
					cout << "ERROR" << endl ;
					break ;
				}
		}
		
	}
}
void win ()
{
	cout << "YOOOOOOOOOOOU WON !" ;
	system ("Color 21") ;
	exit (0) ;
	
}
void gameover ()
{
	cout << endl << "YOU LOST !!!!" ;
	system("Color 04") ;
	exit(0) ;
	
}