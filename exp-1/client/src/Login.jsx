import React, { useState } from "react";
import axios from "axios";

const Login = () => {
      const [email, setEmail] = useState("");
      const [password, setPassword] = useState("");
      const [message, setMessage] = useState("");

      const handleSubmit = async (e) => {
            e.preventDefault();
            try {
                  const response = await axios.post(
                        "http://localhost:3000/api/login",
                        { email, password }
                  );
                  setMessage(response.data.message);
            } catch (error) {
                  setMessage("Login failed. Please try again.");
            }
      };

      return (
            <div className="flex items-center justify-center min-h-screen bg-gray-900">
                  <div className="w-full max-w-md p-8 space-y-6 bg-gray-800 rounded shadow-md">
                        <h2 className="text-2xl font-bold text-center text-white">
                              Login
                        </h2>
                        <form onSubmit={handleSubmit} className="space-y-4">
                              <div>
                                    <label
                                          htmlFor="email"
                                          className="block text-sm font-medium text-gray-300"
                                    >
                                          Email
                                    </label>
                                    <input
                                          type="email"
                                          id="email"
                                          value={email}
                                          onChange={(e) =>
                                                setEmail(e.target.value)
                                          }
                                          required
                                          className="w-full px-3 py-2 mt-1 border border-gray-600 bg-gray-700 text-white rounded-md focus:outline-none focus:ring focus:ring-indigo-500"
                                    />
                              </div>
                              <div>
                                    <label
                                          htmlFor="password"
                                          className="block text-sm font-medium text-gray-300"
                                    >
                                          Password
                                    </label>
                                    <input
                                          type="password"
                                          id="password"
                                          value={password}
                                          onChange={(e) =>
                                                setPassword(e.target.value)
                                          }
                                          required
                                          className="w-full px-3 py-2 mt-1 border border-gray-600 bg-gray-700 text-white rounded-md focus:outline-none focus:ring focus:ring-indigo-500"
                                    />
                              </div>
                              <button
                                    type="submit"
                                    className="w-full px-4 py-2 font-bold text-white bg-indigo-600 rounded hover:bg-indigo-700 focus:outline-none focus:ring focus:ring-indigo-500"
                              >
                                    Login
                              </button>
                        </form>
                        {message && (
                              <p className="mt-4 text-center text-blue-400">
                                    {message}
                              </p>
                        )}
                  </div>
            </div>
      );
};

export default Login;
