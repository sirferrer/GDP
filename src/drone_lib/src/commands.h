class commands
{
    public:
        commands();
        commands(int argc, char **argv, float rate);

        void await_Connection();
        void set_Offboard();
        void set_Armed();
};
