import express from "express";
import connectDB from "./db.js";
import cors from "cors";

const app = express();
const port = 3000;

connectDB();

app.get("/", (req, res) => {
      res.send("Hello World");
});

app.use(express.json());

app.use(
      cors({
            origin: "*",
      })
);

app.listen(port, () => {
      console.log(`Server is running on port ${port}`);
});

import userRouter from "./routes/user.route.js";
app.use("/api", userRouter);
