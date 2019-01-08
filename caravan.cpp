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
#include <stdlib.h>

typedef struct _node{
  PackAnimal pack_animal;
  struct _node* _next;
}Node;

struct CaravanImplementation{
  Node* _head;
};

Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
  caravan->_head = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  int count = 0;

  Node* current = caravan->_head;
  while(current != 0){
    count++;
    current = current->_next;
  }
  return count;
}

void delete_caravan(Caravan caravan)
{
  int length = get_length(caravan);

  for(int i = 0; i < length; i++){
    Node* _head = caravan->_head;
    caravan->_head = _head->_next;
    sfree(_head);
  }

  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if((animal == 0) || (get_caravan(animal) == caravan)){
    return;
  }
  if(get_caravan(animal) != 0){
    remove_pack_animal(get_caravan(animal), animal);
  }

  add_to_caravan(animal, caravan);
  Node* new_node = (Node*)malloc(sizeof(Node));

  new_node->pack_animal = animal;
  new_node->_next = caravan->_head;
  caravan->_head = new_node;
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  Node* current = caravan->_head;

  if(current == 0 || animal == 0){
    return;
  }

  remove_from_caravan(animal, caravan);
  if(current->pack_animal == animal){
    caravan->_head = current->_next;
    sfree(current);
    return;
  }

  while((current->_next != 0) && (current->_next->pack_animal != animal)){
    current = current->_next;
  }

  if(current->_next == 0){
    return;
  }

  Node* node__next = current->_next;
  current->_next = node__next->_next;
  sfree(node__next);
}

int get_caravan_load(Caravan caravan)
{
  int length = get_length(caravan);
  int load_count = 0;
  Node* current = caravan->_head;

  for(int i = 0; i < length; i++){
    load_count += get_load(current->pack_animal);
    current = current->_next;
  }
  return load_count;
}

void unload(Caravan caravan)
{
  int length = get_length(caravan);

  Node* current = caravan->_head;

  for(int i = 0; i < length; i++){
    unload(current->pack_animal);
    current = current->_next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  int lowest_speed = 51;
  int length = get_length(caravan);

  Node* current = caravan->_head;

  for(int i = 0; i < length; i++){
    if(get_actual_speed(current->pack_animal) < lowest_speed){
      lowest_speed = get_actual_speed(current->pack_animal);
    }
    current = current->_next;
  }

  if(lowest_speed == 51){
    lowest_speed = 0;
  }
  return lowest_speed;
}
