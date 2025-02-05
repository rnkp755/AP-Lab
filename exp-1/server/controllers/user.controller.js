import User from "../models/user.model.js";

const createUser = async (req, res) => {
      try {
            const { email, password } = await req.body;
            if (!email || !password) {
                  res.status(400).json({
                        message: "Please provide email and password",
                  });
                  return;
            }
            const user = new User({
                  email,
                  password,
            });
            const existingUser = await User.findOne({ email: req.body.email });
            if (existingUser) {
                  res.status(202).json({
                        message: "Signup failed. User already exists",
                  });
                  return;
            }
            await user.save();
            res.status(201).json({ message: "User created successfully" });
      } catch (err) {
            res.status(500).json(err);
      }
};

const loginUser = async (req, res) => {
      try {
            const user = await User.findOne({ email: req.body.email });
            if (!user) {
                  res.status(404).json({ message: "User not found" });
            } else if (user.password !== req.body.password) {
                  res.status(401).json({ message: "Invalid password" });
            } else {
                  res.status(200).json({ message: "Login successful" });
            }
      } catch (err) {
            res.status(500).json(err);
      }
};

export { createUser, loginUser };
