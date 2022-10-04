#include<iostream>
#include<string>
using namespace std;
class UndoRedo{
    private:
        string text;        //string of text
        string undo[100];   //stack for undo operation
        string redo[100];   //stack for redo operation
        int topUndo = 0;
        int topRedo = 0;
    public:
        UndoRedo(){ //default constructor
            text = "";
        }
        UndoRedo(string str){ //constructor
            text = str;
            addUndoStack(str);
        }
        void addText(string str) //add text to the string
        {
            text.append(str);
            addUndoStack(str);
        }
        string getText() //print text
        {
            return text;
        }

        void Undo() //undo operation
        {
            if(topUndo>0){
                topUndo--;
                addRedoStack(undo[topUndo]);
                text.clear();
                for(int i=0;i<topUndo;i++)
                {
                    text+=undo[i];
                }
            }


        }
        void Redo() //redo operation
        {
            if(topRedo>0){
                topRedo--;
                addText(redo[topRedo]);
            }


        }

    private:

        void addUndoStack(string str) //add pieces of text to stack while editing string
        {
            undo[topUndo] = str;
            topUndo++;
        }
        void addRedoStack(string str) // add pieces of text to redo stack while undo operation
        {
            redo[topRedo] = str;
            topRedo++;
        }


};

int main()
{
    UndoRedo text;
    string mytext;
    int choice;
     while(1)
    {
        cout<<"Enter 1 to add text."<<endl;
        cout<<"Enter 2 to undo text."<<endl;
        cout<<"Enter 3 to redo text."<<endl;
        cout<<"Enter 4 to get text."<<endl;
        cout<<"Enter 5 to Terminate."<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"EDIT : "+text.getText();
            getline(cin>>ws,mytext);
            text.addText(mytext);
            break;
        case 2:
            text.Undo();
            cout<<text.getText()<<endl;
            break;
        case 3:
            text.Redo();
            cout<<text.getText()<<endl;
            break;
        case 4:
            cout<<text.getText()<<endl;
            break;
        case 5:
            exit(1);

        }

    }


    return 0;
}
