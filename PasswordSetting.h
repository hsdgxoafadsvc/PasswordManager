struct PasswordSetting{
    bool use_small_letters = true;
    bool use_big_letters = true;
    bool use_numbers = true;
    bool use_special_characters = true;
    bool special_set = false;
    std::string data = "abcdefghijklmnopqrstuvwxyz
                        ABCDEFGHIJKLMNOPQRSTUVWXYZ
                        0987654321
                        ~`!@#$%^&*()_+-={}|[]:>?<;.,";
    std::string mask = "22222222222222222222222222
                        22222222222222222222222222
                        2222222222
                        2222222222222222222222222222";
    int mask_order = 2;
    int pass_len = 64;
}defaultSetting;