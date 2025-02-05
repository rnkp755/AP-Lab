import mongoose, { Schema } from "mongoose";

const userSchema = new Schema({
      email: {
            type: String,
            required: true,
            unique: true,
            lowercase: true,
            trim: true,
      },
      password: {
            type: String,
            required: true,
      },
});

const User = mongoose.model("user", userSchema);
export default User;
