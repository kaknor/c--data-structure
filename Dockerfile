FROM gcc:5.4

COPY . /usr/src/c--data-structure

WORKDIR /usr/src/c--data-structure/sequential_structures/list

RUN make all
RUN make test