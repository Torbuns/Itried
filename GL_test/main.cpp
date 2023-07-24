#include<iostream>
#include <filesystem>
#include <vector>

using namespace std;

void search(vector<string>& paths, const string& current_path, string& x)
{
    for(const auto& temp: filesystem::directory_iterator(current_path))
    {
        filesystem::file_status status = filesystem::status(temp);
        {
            if(paths.size() != 0) return;
            else if(temp.is_regular_file() && temp.path().filename().string() == x)
            {
                paths.push_back(temp.path().string());
            }
            else if(filesystem::is_directory(status) && filesystem::exists(status))
            {
                search(paths, temp.path().string(), x);
            }
        }

    }
}

int main()
{
    //name.faromat
    string x = "Hello.txt";
    vector<string>paths;
    search(paths, "Ñ:\\", x);

    if(paths.size() == 0)
    {
        cout<<"File is not found"<<endl;
    }
    else{
        for(int i = 0; i < paths.size(); i++)
        cout<<paths[i]<<endl;
    }

    return 0;
}
