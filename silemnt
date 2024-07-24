if (not getgenv().Loaded) then
local userInputService = game:GetService("UserInputService")

local function CheckAnti(Plr) -- // Anti-aim detection
    if Plr.Character.HumanoidRootPart.Velocity.Y < -70 then
        return true
    elseif Plr and (Plr.Character.HumanoidRootPart.Velocity.X > 450 or Plr.Character.HumanoidRootPart.Velocity.X < -35) then
        return true
    elseif Plr and Plr.Character.HumanoidRootPart.Velocity.Y > 60 then
        return true
    elseif Plr and (Plr.Character.HumanoidRootPart.Velocity.Z > 35 or Plr.Character.HumanoidRootPart.Velocity.Z < -35) then
        return true
    else
        return false
    end
end

local function getnamecall()
     if game.PlaceId == 2788229376 or game.PlaceId == 7213786345 or game.PlaceId == 16033173781 or game.PlaceId == 16158576873 then 
        return "UpdateMousePosI"
    elseif game.PlaceId == 5602055394 or game.PlaceId == 7951883376 then
        return "MousePos"
    elseif game.PlaceId == 9825515356 then
        return "GetMousePos"
    end
end

function MainEventLocate()
    for _,v in pairs(game:GetService("ReplicatedStorage"):GetDescendants()) do
        if v.Name == "MainEvent" then
            return v
        end
    end
end

local Locking = false
local Players = game:GetService("Players")
local Client = Players.LocalPlayer
local Plr = nil -- Initialize Plr here

-- 360 on bind
local UserInputService = game:GetService("UserInputService")
local RunService = game:GetService("RunService")
local Camera = workspace.CurrentCamera
local Toggle = false -- Initialize Toggle to false

local function OnKeyPress(Input, GameProcessedEvent)
    if Input.KeyCode == getgenv().Sync.Aimbot.Keybind and not GameProcessedEvent then 
        Toggle = not Toggle
    elseif Input.KeyCode == getgenv().Sync.Macro.SpeedGlitchKey then
        if getgenv().Sync.Macro.Enabled then 
            getgenv().Sync.Macro.SpeedGlitch = not getgenv().Sync.Macro.SpeedGlitch
            if getgenv().Sync.Macro.SpeedGlitch then
                repeat
                    game:GetService("RunService").Heartbeat:Wait()
                    keypress(0x49)
                    game:GetService("RunService").Heartbeat:Wait()
                    keypress(0x4F)
                    game:GetService("RunService").Heartbeat:Wait()
                    keyrelease(0x49)
                    game:GetService("RunService").Heartbeat:Wait()
                    keyrelease(0x4F)
                    game:GetService("RunService").Heartbeat:Wait()
                until not getgenv().Sync.Macro.SpeedGlitch
            end
        end
    end
end

UserInputService.InputBegan:Connect(OnKeyPress)

UserInputService.InputBegan:Connect(function(keygo, ok)
    if (not ok) then
        if (keygo.KeyCode == getgenv().Synce.Aimbot.Keybind) then
            Locking = not Locking
            if Locking then
                Plr = getClosestPlayerToCursor()
            elseif not Locking then
                if Plr then
                    Plr = nil
                end
            end
        end
    end
end)

function getClosestPlayerToCursor()
    local closestDist = math.huge
    local closestPlr = nil
    for _, v in ipairs(Players:GetPlayers()) do
        if v ~= Client and v.Character and v.Character:FindFirstChild("Humanoid") and v.Character.Humanoid.Health > 0 then
            local screenPos, cameraVisible = workspace.CurrentCamera:WorldToViewportPoint(v.Character.HumanoidRootPart.Position)
            if cameraVisible then
                local distToMouse = (Vector2.new(UserInputService:GetMouseLocation().X, UserInputService:GetMouseLocation().Y) - Vector2.new(screenPos.X, screenPos.Y)).Magnitude
                if distToMouse < closestDist then
                    closestPlr = v
                    closestDist = distToMouse
                end
            end
        end
    end
    return closestPlr
end

function getClosestPartToCursor(Player)
    local closestPart, closestDist = nil, math.huge
    if Player.Character and Player.Character:FindFirstChild("Humanoid") and Player.Character:FindFirstChild("Head") and Player.Character.Humanoid.Health ~= 0 and Player.Character:FindFirstChild("HumanoidRootPart") then
        for i, part in pairs(Player.Character:GetChildren()) do
            if part:IsA("BasePart") then
                local screenPos, cameraVisible = workspace.CurrentCamera:WorldToViewportPoint(part.Position)
                local distToMouse = (Vector2.new(UserInputService:GetMouseLocation().X, UserInputService:GetMouseLocation().Y) - Vector2.new(screenPos.X, screenPos.Y)).Magnitude
                if distToMouse < closestDist and table.find(getgenv().Howl.Aimbot.MultipleTargetPart, part.Name) then
                    closestPart = part
                    closestDist = distToMouse
                end
            end
        end
        return closestPart
    end
end

game:GetService("RunService").RenderStepped:Connect(function()
    if Plr and Plr.Character then
        if getgenv().Howl.Aimbot.NearestPart == true and getgenv().Synce.Aimbot.Basic == false then
            getgenv().Howl.Aimbot.TargetPart = tostring(getClosestPartToCursor(Plr))
        elseif getgenv().Howl.Aimbot.Basic == true and getgenv().Synce.Aimbot.NearestPart == false then
            getgenv().Howl.Aimbot.TargetPart = getgenv().Synce.Aimbot.TargetPart
        end
    end
end)

local function getVelocity(Player)
    local Old = Player.Character.HumanoidRootPart.Position
    wait(0.145)
    local Current = Player.Character.HumanoidRootPart.Position
    return (Current - Old) / 0.145
end

local function GetShakedVector3(Setting)
    return Vector3.new(math.random(-Setting * 1e9, Setting * 1e9), math.random(-Setting * 1e9, Setting * 1e9), math.random(-Setting * 1e9, Setting * 1e9)) / 1e9;
end

local v = nil
game:GetService("RunService").Heartbeat:Connect(function(deltaTime)
    if Plr ~= nil and Plr.Character and Plr.Character:FindFirstChild("HumanoidRootPart") then
        v = getVelocity(Plr)
    end
end)

local mainevent = game:GetService("ReplicatedStorage").MainEvent

Client.Character.ChildAdded:Connect(function(child)
    if child:IsA("Tool") and child:FindFirstChild("MaxAmmo") then
        child.Activated:Connect(function()
            if Plr and Plr.Character then
                local Position = Plr.Character.Humanoid:GetState() == Enum.HumanoidStateType.Freefall and Plr.Character[getgenv().Sync.Aimbot.TargetPart].Position + Vector3.new(0, getgenv().Sync.Aimbot.JumpOffset, 0) or Plr.Character[getgenv().Sync.Aimbot.TargetPart].Position
                if not CheckAnti(Plr) then
                    mainevent:FireServer("UpdateMousePosI", Position + ((Plr.Character.HumanoidRootPart.Velocity) * getgenv().Sync.Aimbot.Prediction))
                else
                    mainevent:FireServer("UpdateMousePos", Position + ((Plr.Character.Humanoid.MoveDirection * Plr.Character.Humanoid.WalkSpeed) * getgenv().Sync.Aimbot.Prediction))
                end
            end
        end)
    end
end)

Client.CharacterAdded:Connect(function(character)
    character.ChildAdded:Connect(function(child)
        if child:IsA("Tool") and child:FindFirstChild("MaxAmmo") then
            child.Activated:Connect(function()
                if Plr and Plr.Character then
                    local Position = Plr.Character.Humanoid:GetState() == Enum.HumanoidStateType.Freefall and Plr.Character[getgenv().Sync.Aimbot.TargetPart].Position + Vector3.new(0, getgenv().Sync.Aimbot.JumpOffset, 0) or Plr.Character[getgenv().Sync.Aimbot.TargetPart].Position
                    if not CheckAnti(Plr) then
                        mainevent:FireServer("UpdateMousePosI", Position + ((Plr.Character.HumanoidRootPart.Velocity) * getgenv().Howl.Aimbot.Prediction))
                    else
                        mainevent:FireServer("UpdateMousePos", Position + ((Plr.Character.Humanoid.MoveDirection * Plr.Character.Humanoid.WalkSpeed) * getgenv().Sync.Aimbot.Prediction))
                    end
                end
            end)
        end
    end)
end)

game:GetService("RunService").RenderStepped:Connect(function()
    if Plr ~= nil and Plr.Character then
        local Position = Plr.Character.Humanoid:GetState() == Enum.HumanoidStateType.Freefall and Plr.Character[getgenv().Howl.Aimbot.TargetPart].Position + Vector3.new(0, getgenv().Sync.Aimbot.JumpOffset, 0) or Plr.Character[getgenv().Sync.Aimbot.TargetPart].Position
        if not CheckAnti(Plr) then
            local Main = CFrame.new(workspace.CurrentCamera.CFrame.p, Position + ((Plr.Character.HumanoidRootPart.Velocity) * getgenv().Sync.Aimbot.AimBotSkid) + GetShakedVector3(getgenv().Sync.Aimbot.Shake))
            workspace.CurrentCamera.CFrame = workspace.CurrentCamera.CFrame:Lerp(Main, getgenv().Sync.Aimbot.Amount, Enum.EasingStyle.Sine, Enum.EasingDirection.InOut)
        else
            local Main = CFrame.new(workspace.CurrentCamera.CFrame.p, Position + ((Plr.Character.Humanoid.MoveDirection * Plr.Character.Humanoid.WalkSpeed) * getgenv().Sync.Aimbot.AimBotSkid) + GetShakedVector3(getgenv().Sync.Aimbot.CameraShake))
            workspace.CurrentCamera.CFrame = workspace.CurrentCamera.CFrame:Lerp(Main, getgenv().Sync.Aimbot.Amount, Enum.EasingStyle.Sine, Enum.EasingDirection.InOut)
        end
    end
    if getgenv().Sync.Checks.PlayerDeath == true and Plr and Plr.Character then
        local KOd = Plr.Character:WaitForChild("BodyEffects")["K.O"].Value
        local Grabbed = Plr.Character:FindFirstChild("GRABBING_CONSTRAINT") ~= nil
        if Plr.Character.Humanoid.Health < 1 or KOd or Grabbed then
            if Locking == true then
                Plr = nil
                Locking = false
            end
        end
    end
    if getgenv().Sync.Checks.TargetDeath == true and Plr and Plr.Character:FindFirstChild("Humanoid") then
        if Plr.Character.Humanoid.health < 1 then
            if Locking == true then
                Plr = nil
                Locking = false
            end
        end
    end
    if getgenv().Sync.Checks.PlayerDeath  == true and Client.Character and Client.Character:FindFirstChild("Humanoid") and Client.Character.Humanoid.health < 1 then
        if Locking == true then
            Plr = nil
            Locking = false
        end
    end
    if getgenv().Sync.Safety.AntiGroundShots == true and Plr.Character.Humanoid.Jump == true and Plr.Character.Humanoid.FloorMaterial == Enum.Material.Air then
        pcall(function()
            local TargetVelv5 = Plr.Character.HumanoidRootPart
    TargetVelv5.Velocity = Vector3.new(TargetVelv5.Velocity.X, math.abs(TargetVelv5.Velocity.Y * 0.36),
     TargetVelv5.Velocity.Z)
            TargetVelv5.AssemblyLinearVelocity = Vector3.new(TargetVelv5.Velocity.X, math.abs(TargetVelv5.Velocity.Y * 0.36), TargetVelv5.Velocity.Z)
        end)
    end
end)

if getgenv().Sync.Spin.Enabled == true then
    
    local Players = game:GetService("Players")
    local UserInputService = game:GetService("UserInputService")
    local RunService = game:GetService("RunService")
    local Camera = workspace.CurrentCamera
    local Toggle = getgenv().Sync.Spin.Enabled
    local RotationSpeed = getgenv().Sync.Spin.SpinSpeed
    local Keybind = getgenv().Sync.Spin.Keybind
    
    local function OnKeyPress(Input, GameProcessedEvent)
        if Input.KeyCode == Keybind and not GameProcessedEvent then 
            Toggle = not Toggle
        end
    end
    
    UserInputService.InputBegan:Connect(OnKeyPress)
    
    local LastRenderTime = 0
    local TotalRotation = 0
    
    local function RotateCamera()
        if Toggle then
            local CurrentTime = tick()
            local TimeDelta = math.min(CurrentTime - LastRenderTime, 0.01)
            LastRenderTime = CurrentTime
    
            local RotationAngle = RotationSpeed * TimeDelta
            local Rotation = CFrame.fromAxisAngle(Vector3.new(0, 1, 0), math.rad(RotationAngle))
            Camera.CFrame = Camera.CFrame * Rotation
    
            TotalRotation = TotalRotation + RotationAngle
            if TotalRotation >= getgenv().Sync.Spin.Degrees then 
                Toggle = false
                TotalRotation = 0
            end
        end
    end
    
    RunService.RenderStepped:Connect(RotateCamera)
    end

getgenv().Loaded = true -- end of the script
else
    game:GetService("StarterGui"):SetCore("SendNotification", {
        Title = "Sync.cc",
        Text = "Updated Table",
        Duration = 0.001
    })
end
