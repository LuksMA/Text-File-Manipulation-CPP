#include "file.h"


/** Clone file **/
int clone_file(const string &path, const string &path_clone)
{
    //Open file
    ifstream FILE;
	FILE.open(path.c_str(), std::ios::in);

    //error
	if (FILE.is_open() == false)
        return -1;


	//Create temp file
	ofstream FILE_CLONE;
	FILE_CLONE.open(path_clone.c_str(), std::ios::out);


	//copy file original for temp
	while (FILE.eof() == false)
	{
        string line = "";
        getline(FILE, line);


        //if not end then insert charactere '\n'
        if (FILE.eof() == false)
            FILE_CLONE << line << endl;

        else
            FILE_CLONE << line;
	}


	//close file and re-open (for reset)
	FILE.close();
	FILE_CLONE.close();

	return 0;
}


/** Write Comment **/
int write_comment(string path, int n_line, string comment)
{
    ofstream FILE;
    ifstream FILE_TMP;

    ///if comment in last line
    if (n_line <= 0)
    {
        FILE.open(path.c_str(), std::ios::out | std::ios::app);
        //error
        if (FILE.is_open() == false)
            return -1;

        FILE << endl << comment;
        FILE.close();

        return 0;
    }

    //path temp
    string path_tmp = path + "-tmp_file";

    ///Clone File
    if (clone_file(path, path_tmp) == -1)
        return -1;


    FILE.open(path.c_str(), std::ios::out);
    FILE_TMP.open(path_tmp.c_str(), std::ios::in);


    /* Read File */
    bool end_file = false;
    int current_line = 0;
    bool comment_exist = false;
    while (end_file == false)
    {
        //get line
        string line = "";
        getline(FILE_TMP, line);

        end_file = FILE_TMP.eof();

        current_line ++;

        //if comment already exists
        if (line == comment)
            comment_exist = true;


        if (current_line == n_line &&
            comment_exist == false)
        {
            FILE << comment << endl;
            comment_exist = true;
        }

        //copy line
        FILE << line;

        if (end_file == false)
            FILE << endl;

        //check if line is more greater thant file
        if (end_file == true && comment_exist == false)
            FILE << endl << comment;

    }/* End read file */

    FILE.close();
    FILE_TMP.close();

    if (comment_exist == true) return -2;

    return 0;
}


/** Write Variable **/
int write_variable(string path, string variable_name, string variable_value)
{
    //path temp
    string path_tmp = "." + path + "_tmp-file";

    ///Clone File
    if (clone_file(path, path_tmp) == -1)
        return -1;


    //flag for controll if the variable has already been written
    bool flag_register = false;


    ofstream FILE;
    ifstream FILE_TMP;


    FILE.open(path.c_str(), std::ios::out);
    FILE_TMP.open(path_tmp.c_str(), std::ios::in);


    /* Read File */
    bool end_file = false;
    while (end_file == false)
    {
        //get line
        string line = "";
        getline(FILE_TMP, line);

        end_file = FILE_TMP.eof();


        //check for comment
        if (line.compare(0,2,"//") == 0)
        {
            //copy line
            FILE << line;

            if (end_file == false)
                FILE << endl;

            continue;
        }

        //check for equal position
        std::size_t pos_equal;
        pos_equal = line.find('=');

        //if not found ignore line
        if (pos_equal == std::string::npos)
        {
            //copy line
            FILE << line;

            if (end_file == false)
                FILE << endl;

            continue;
        }


        //get variable name
        string tmp_name_var = line.substr (0, pos_equal);

        //remove blank characters in final of string
        while (tmp_name_var[tmp_name_var.length() - 1] == ' ')
        {
            tmp_name_var.resize(tmp_name_var.length() - 1);
        }


        ///check if the desired variable, if it is, overwrite the original file
        if (tmp_name_var == variable_name)
        {
            //registrar a variavel
            flag_register = true;

            FILE << tmp_name_var << " = " << variable_value;

            if (end_file == false)
                FILE << endl;
        }
        //else, copy line
        else
        {
            //copy line
            FILE << line;

            if (end_file == false)
                FILE << endl;

            continue;
        }


    }/* End read file */

    ///if the variable is missing write a new line in final of file
    if (flag_register == false)
        FILE << endl << variable_name << " = " << variable_value;


    FILE.close();
    FILE_TMP.close();

    //delete temp file
    remove(path_tmp.c_str());

	return 0;
}


/** Read Variable **/
string read_variable(string path, string variable_name)
{
    //open for read
    ifstream FILE;
	FILE.open(path.c_str(), std::ios::in);


    //error
	if (FILE.is_open() == false)
        return "erro_file";


	/* Read File */
	while (FILE.eof() == false)
	{
        //get line
        string line = "";
        getline(FILE, line);


        //check for comment
        if (line.compare(0,2,"//") == 0)
            continue;


        //check for equal signal
        size_t pos_equal;
        pos_equal = line.find('=');

        //if not found ignore line
        if (pos_equal == std::string::npos)
            continue;

        //get variable name
        string tmp_name_var = line.substr (0, pos_equal);

        //remove blank characters in final of string
        while (tmp_name_var[tmp_name_var.length() - 1] == ' ')
        {
            tmp_name_var.resize(tmp_name_var.length() - 1);
        }

        //if the name of the variables are different ignore line
        if (tmp_name_var != variable_name)
            continue;

        //now get value
        string value_var = line.substr (pos_equal+1);

        //remove blank characters in start of string
        while (value_var[0] == ' ')
        {
            value_var = value_var.substr(1);
        }


        //return value
        FILE.close();
        return value_var;

	}/* End read file */

    //Variable is missing
	FILE.close();
	return "null";
}
