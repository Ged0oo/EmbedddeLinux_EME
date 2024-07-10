#!/usr/bin/python3

from employee_data import id_pass_pairs

def check_user(id, password):
    if id in id_pass_pairs and id_pass_pairs[id] == password :
        return True
    else:
        return False
