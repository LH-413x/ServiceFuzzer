//
// Created by alex on 2019/11/12.
//

enum IDs{
    OPEN,
    WORK,
    CLOSE
};

void work(){}
void open(){}
void close(){}

void rpcSwitch(int id, char* data){
    switch (id) {
        case OPEN:
            open();
        case WORK:
            work();
        case CLOSE:
            close();
    }
}

int main(){
    rpcSwitch(0, nullptr);
}