#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include "my_sorts.h"
using namespace chrono;

int compare_int(int, int);

double time_sort(Sequence<int>* seq, Sequence<int>* (*sort)(Sequence<int>* seq, int (*cmp)(int a, int b))) {
    auto start = high_resolution_clock::now();
    sort(seq, compare_int);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

bool auto_check(Sequence<int>* seq, int (*cmp)(int a, int b)) {
    if (seq->GetLength() == 0)
        return 1;                                   //ïðîñòî ïðîâåðèì, ÷òî êàæäîå ÷èñëî ìåíüøå èëè ðàâíî ñëåä
    for (int i = 0; i < seq->GetLength() - 1; i++) {
        if (cmp(seq->Get(i), seq->Get(i + 1)))
            return 0;
    }
    return 1;
}

 
 
 
void Interface () {
    int choice = 1;
     while (choice)    {
      cout << "_____________________________________________________________________________" << endl;
      cout << "                                                                             " << endl;
      cout << " *** MENU *** " << endl;
      cout << "_____________________________________________________________________________" << endl;
      cout << "1) To sort sequence" << endl;
      cout << "2) To find out the best sort for concrete sequence" << endl;
      cout << "3) To create random sequence and sort it(from your length)" << endl;
      cout << "4) To find out what sort better in sorted, " << endl << "unsorted and randomly sorted sequence" << endl;
      cout << "0) To exit" << endl;
      cout << "_____________________________________________________________________________" << endl;
      cin >> choice;
      
      
      if (choice == 1) {
	  cout << "Length of sequence: " << endl << "length = ";
	  int length = 0;
	  cin >> length;
	  if (0 > length || length > 32000)
	    throw out_of_range (IndexOutOfRangeEx);
	  ArraySequence < int >arr_seq (length);
	  Sequence < int >*seq = &arr_seq;
	  cout << "Enter elements of your sequence: " << endl;
	  for (int i = 0; i < length; i++)	    {
	      int cur_element = 0;
	      cin >> cur_element;
	      seq->Set (i, cur_element);
	    } 
	    cout << "_____________________________________________________________________________"	<< endl;
	    cout << "                                                                             " << endl;
	    cout << "***SORT***" << endl;
	    cout <<	    "_____________________________________________________________________________"	    << endl;
	    cout << "1) Bubble Sort" << endl;
	    cout << "2) Quick Sort" << endl;
	    cout << "3) Merge Sort" << endl;
	    cout << "4) Sort with Binary Tree" << endl;
	    cin >> choice;
	    cout << "Your sequence:" << endl;
	    seq->print ();
	    cout << "Sorted sequence: " << endl;
	  
            if (choice == 1) {
	        Bubble_Sort (seq, compare_int)->print ();
	        }
	        else if (choice == 2) {
	        Quick_Sort_seq (seq, compare_int)->print ();
	        }
	        else if (choice == 3) {
	        Merge_Sort_for_seq (seq, compare_int)->print ();
	        }
	        else if (choice == 4) {
	      	Sort_With_Tree (seq, compare_int)->print ();
	        }
	  choice = 1;
	}
      
 
 
    else if (choice == 2)	{
	  cout << "Length of sequence: " << endl << "length = ";
	  int length = 0;
	  cin >> length;
	  if (0 > length || length > 32000)
	    throw out_of_range (IndexOutOfRangeEx);
	  ArraySequence < int >arr_seq1 (length);
	  Sequence < int >*seq1 = &arr_seq1;
	  cout << "Enter elements of your sequence: " << endl;
	  for (int i = 0; i < length; i++)	    {
	      int cur_element = 0;
	      cin >> cur_element;
	      seq1->Set (i, cur_element);
	    } 
	    
	    ArraySequence < int >arr_seq2 (seq1);
	    Sequence < int >*seq2 = &arr_seq2;
	    ArraySequence < int >arr_seq3 (seq1);	// P4P;Q 2 P8 3 QP>P7P4P0P4P8P< QP5 P6P5 P<P0QQP8P2Q
	    Sequence < int >*seq3 = &arr_seq3;
	    ArraySequence < int >arr_seq4 (seq1);
	    Sequence < int >*seq4 = &arr_seq4;
	  
 //___________________________________________________________________
		
		//проверка BubbleSort
	      double best_time = time_sort (seq1, Bubble_Sort);
	      string best_name = "Bubble Sort";
	      cout << "Bubble Sort: " << best_time << " microsecond " << endl;
	      
 
		//проверка MergeSort
	      double time_for_merge = time_sort (seq2, Merge_Sort_for_seq);
	      if (time_for_merge < best_time)		{
		      best_time = time_for_merge;
		      best_name = "Merge Sort";
	      }
	      else if (time_for_merge == best_time)	{
		      best_name += " and merge sort";
		  }
	      cout << "Merge Sort: " << time_for_merge << " microsecond " << endl;
	      
 
		//проверка BST
	      double time_for_BST = time_sort (seq3, Sort_With_Tree);	// C1C,C.C2C0C(C, C-C  CCC 
	      if (time_for_BST < best_time) {
		      best_time = time_for_BST;
		      best_name = "sort with Binary Tree";
		  }
	      else if (time_for_BST == best_time) {
		      best_name += " and sort with Binary Tree";
		  }
	      cout << "Binary Tree sort: " << time_for_BST << " microsecond"<< endl;
	      cout << "                                                    "<< endl;
	      cout << "The best sort is " << best_name << ", sorted for " <<	best_time << " microseconds" << endl;
	    }
	    //___________________________________________________________________
	 
      
 
    else if (choice == 3){
	cout << "Enter your length: " << endl << "length = ";
	  int length = 0;
	  cin >> length;
	  if (0 > length || length > 32000)
	    throw out_of_range (IndexOutOfRangeEx);
	  ArraySequence < int >random_arr (length);
	  Sequence < int >*seq = &random_arr;
	  for (int i = 0; i < length; i++)	    {
	      seq->Set (i, -5000 + rand () % 10000);
	    } 
	    cout << "Generated sequence:" << endl;
	    seq->print ();
	  
	    cout << "_____________________________________________________________________________"	<< endl;
	    cout << "                                                                             " << endl;
	    cout << " ***SORT*** " << endl;
	    cout <<	"_____________________________________________________________________________"	    << endl;
	    cout << "1) Bubble Sort" << endl;
	    cout << "2) Quick Sort" << endl;
	    cout << "3) Merge Sort" << endl;
	    cout << "4) Sort with Binary Tree" << endl;
	    cin >> choice;
	    cout << "Your sequence:" << endl;
	    seq->print ();
	    cout << "Sorted sequence: " << endl;
	  
            if (choice == 1) {
	        Bubble_Sort (seq, compare_int)->print ();
	        }
	        else if (choice == 2) {
	        Quick_Sort_seq (seq, compare_int)->print ();
	        }
	        else if (choice == 3) {
	        Merge_Sort_for_seq (seq, compare_int)->print ();
	        }
	        else if (choice == 4) {
	      	Sort_With_Tree (seq, compare_int)->print ();
	        }
	  choice = 3;
	}
      
 
    else if (choice == 4) {
	  cout << "1) Best sort for sorted sequence" << endl;
	  cout << "2) Best sort for backward sorted sequence" << endl;
	  cout << "3) Best sort for random sorted sequence" << endl;
	  cin >> choice;
	  
	     if (choice == 1) {
	      cout << "Length of sequence: " << endl << "length = ";
	      int length = 0;
	      cin >> length;
	      if (0 > length || length > 32000)
		      throw out_of_range (IndexOutOfRangeEx);
	      ArraySequence < int >sorted_arr (length);
	      Sequence < int >*seq1 = &sorted_arr;
	      for (int i = 0; i < length; i++)		{
		  seq1->Set (i, i - length / 2);
		} 
		cout << "Sorted sequence:" << endl;
	      seq1->print ();
	      
	      ArraySequence < int >arr_seq2 (seq1);
	      Sequence < int >*seq2 = &arr_seq2;
	      ArraySequence < int >arr_seq3 (seq1);	
	      Sequence < int >*seq3 = &arr_seq3;
	      ArraySequence < int >arr_seq4 (seq1);	
	      Sequence < int >*seq4 = &arr_seq4;
	      
 
		//___________________________________________________________________
		
		//проверка BubbleSort
	      double best_time = time_sort (seq1, Bubble_Sort);
	      string best_name = "Bubble Sort";
	      cout << "Bubble Sort: " << best_time << " microsecond " << endl;
	      
 
		//проверка MergeSort
	      double time_for_merge = time_sort (seq2, Merge_Sort_for_seq);
	      if (time_for_merge < best_time)		{
		      best_time = time_for_merge;
		      best_name = "Merge Sort";
	      }
	      else if (time_for_merge == best_time)	{
		      best_name += " and merge sort";
		  }
	      cout << "Merge Sort: " << time_for_merge << " microsecond " << endl;
	      
 
		//проверка BST
	      double time_for_BST = time_sort (seq3, Sort_With_Tree);	
	      if (time_for_BST < best_time) {
		      best_time = time_for_BST;
		      best_name = "sort with Binary Tree";
		  }
	      else if (time_for_BST == best_time) {
		      best_name += " and sort with Binary Tree";
		  }
	      cout << "Binary Tree sort: " << time_for_BST << " microsecond"<< endl;
	      cout << "                                                    "<< endl;
	      cout << "The best sort is " << best_name << ", sorted for " <<	best_time << " microseconds" << endl;
	    }
	  
 
        else if (choice == 2) {
	      cout << "Length of sequence: " << endl << "length = ";
	      int length = 0;
	      cin >> length;
	      if (0 > length || length > 32000)
		     throw out_of_range (IndexOutOfRangeEx);
	      ArraySequence < int >sorted_arr (length);
	      Sequence < int >*seq1 = &sorted_arr;
	      for (int i = 0; i < length; i++)		{
		  seq1->Set (i, length / 2 - i);
		  } 
		  cout << "Backward sorted sequence:" << endl;
	      seq1->print ();
	      
	      ArraySequence < int >arr_seq2 (seq1);
	      Sequence < int >*seq2 = &arr_seq2;
	      ArraySequence < int >arr_seq3 (seq1);	
	      Sequence < int >*seq3 = &arr_seq3;
	      ArraySequence < int >arr_seq4 (seq1);	
	      Sequence < int >*seq4 = &arr_seq4;
	      
 
 
		//___________________________________________________________________
		
		
		//проверка BubbleSort
	      double best_time = time_sort (seq1, Bubble_Sort);
	      string best_name = "Bubble Sort";
	      cout << "Bubble Sort: " << best_time << " microsecond " << endl;
	      
 
		//проверка MergeSort
	      double time_for_merge = time_sort (seq2, Merge_Sort_for_seq);
	      if (time_for_merge < best_time)		{
		      best_time = time_for_merge;
		      best_name = "Merge Sort";
	      }
	      else if (time_for_merge == best_time)	{
		      best_name += " and merge sort";
		  }
	      cout << "Merge Sort: " << time_for_merge << " microsecond " << endl;
	      
 
		//проверка BST
	      double time_for_BST = time_sort (seq3, Sort_With_Tree);	
	      if (time_for_BST < best_time) {
		      best_time = time_for_BST;
		      best_name = "sort with Binary Tree";
		  }
	      else if (time_for_BST == best_time) {
		      best_name += " and sort with Binary Tree";
		  }
	      cout << "Binary Tree sort: " << time_for_BST << " microsecond"<< endl;
	      cout << "                                                    "<< endl;
	      cout << "The best sort is " << best_name << ", sorted for " << best_time << " microseconds" << endl;
	    }

	  
 
        else if (choice == 3) {
	      cout << "Length of sequence: " << endl << "length = ";
	      int length = 0;
	      cin >> length;
	      if (0 > length || length > 32000)
		      throw out_of_range (IndexOutOfRangeEx);
	      ArraySequence < int >sorted_arr (length);
	      Sequence < int >*seq1 = &sorted_arr;
	      for (int i = 0; i < length; i++) {
		  seq1->Set (i, -length / 2 + rand () % length);
	 	  } 
		  cout << "Randomly sorted sequence:" << endl;
	      seq1->print ();
	      
	      ArraySequence < int >arr_seq2 (seq1);
	      Sequence < int >*seq2 = &arr_seq2;
	      ArraySequence < int >arr_seq3 (seq1);
	      Sequence < int >*seq3 = &arr_seq3;
	      ArraySequence < int >arr_seq4 (seq1);
	      Sequence < int >*seq4 = &arr_seq4;
	      
 
 
		//___________________________________________________________________
		
		//проверка BubbleSort
	      double best_time = time_sort (seq1, Bubble_Sort);
	      string best_name = "Bubble Sort";
	      cout << "Bubble Sort: " << best_time << " microsecond " << endl;
	      
 
		//проверка MergeSort
	      double time_for_merge = time_sort (seq2, Merge_Sort_for_seq);
	      if (time_for_merge < best_time)		{
		      best_time = time_for_merge;
		      best_name = "Merge Sort";
	      }
	      else if (time_for_merge == best_time)	{
		      best_name += " and merge sort";
		  }
	      cout << "Merge Sort: " << time_for_merge << " microsecond " << endl;
	      
 
		//проверка BST
	      double time_for_BST = time_sort (seq3, Sort_With_Tree);	
	      if (time_for_BST < best_time) {
		      best_time = time_for_BST;
		      best_name = "sort with Binary Tree";
		  }
	      else if (time_for_BST == best_time) {
		      best_name += " and sort with Binary Tree";
		  }
	      cout << "Binary Tree sort: " << time_for_BST << " microsecond"<< endl;
	      cout << "                                                    "<< endl;
	      cout << "The best sort is " << best_name << ", sorted for " <<	best_time << " microseconds" << endl;
	    }

	    choice = 4;
	}
	
  }

}
