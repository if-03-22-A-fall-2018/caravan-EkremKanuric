/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
  #include "caravan.h"

  struct Node{
    Node* next;

  };
  struct CaravanImplementation{
    Node* head;
  };
  Caravan new_caravan()
  {
    Caravan return_caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
    return_caravan->head = 0;
    return return_caravan;
  }

  int get_length(Caravan caravan)
  {
    /*Node* curr_node = caravan->head;
    int count = 0;
    while (curr_node != 0) {
      count++;
      curr_node = curr_node->next;
    }
    return count;
    */
    return 0;
  }

  void delete_caravan(Caravan caravan)
  {
    Node* curr = caravan->head;
    while (curr != 0) {
      curr = curr->next;
      Node* need_delete = curr;
      sfree(need_delete);
    }
    sfree(caravan);
  }

  void add_pack_animal(Caravan caravan, PackAnimal animal)
  {
  }

  void remove_pack_animal(Caravan caravan, PackAnimal animal)
  {
  }

  int get_caravan_load(Caravan caravan)
  {
    return 0;
  }

  void unload(Caravan caravan)
  {
  }

  int get_caravan_speed(Caravan caravan)
  {
    return 0;
  }
  void optimize_load(Caravan caravan)
  {

  }
