#!/bin/bash
# prepare_my_repo.sh

blih -u theo.cerutti@epitech.eu repository create $1
blih -u theo.cerutti@epitech.eu repository setacl $1 ramassage-tek r
blih -u theo.cerutti@epitech.eu repository getacl $1
