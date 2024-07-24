getgenv().bestar.cc = {
    Aimbot = {
        Keybind = Enum.KeyCode.C,
        AimBot = 0.187,
        Prediction = 0.1247724521,

        ShakeEnabled = false,
        Shake = 0,
        
        Amount = 0.160145,
        Style = "Back",
        Direction = "Inout",

        TargetPart = "HumanoidRootPart",
    
    },
    ['HitBox'] = {
        Part = "HumanoidRootPart",
    },
    ['Resolver'] = {
        Enabled = true,
    },
    ['Silent'] = {
        Prediction = 0.116,
        Detection = {Close = 27, Mid = 38, Far = math.huge},
    },
    ['SpecificDis'] = {
        Enabled = true,
        Prediction = {
            Close = 0.116243115666,
            Mid = 0.1188237,
            Far = 0.1224451,
        },
    },
    ['OffSets'] = {
        Jump = {Amount = 0.90},
        Fall = {Amount = -1.50},
    },  
    ['FieldOfView'] = {
        Enabled = false,
        Size = 240,
        Color = Color3.fromRGB(255, 255, 255),
        Transparency = 1,
        Filled = false,
    },
    ['Air'] = {
        Enabled = true,
        AirPart = "Head",
    },
    ['Checks'] = {
        TargetDeath = true,
        PlayerDeath = true,
        PlayerDeath = true,
    },
    
    ['Macro'] = {
        Enabled = false,
        Keybind = "x",
        Speed = 0.0200,
        Type = "Third", -- "First", "Third"
    },
    
    ['Spin'] = {
        Enabled = true,
        SpinSpeed = 4900,
        Degrees = 360,
        Keybind = Enum.KeyCode.V,
    },
}

loadstring(game:httpsget("https://raw.githubusercontent.com/thinonph/bestar.cc/main/hehe"))()
